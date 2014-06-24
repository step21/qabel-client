
/**
 * @file		qbl-desktop-content.cpp
 * @brief		Address book for the desktop application (Implementation)
 * @author		Michael Ott <michael@king-coder.de>
 *
 * copyright:	(C) 2014 by Qabel GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <QResizeEvent>

#include "qbl-desktop-content-addressbook.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-list-identity.h"

#include "qbl.h"
#include "config/qbl-json-main-config-identity.h"
#include "config/qbl-json-main-config-identity-array.h"
#include "qbl-desktop-addnewcontact.h"

QblDesktopContentAddressbook::QblDesktopContentAddressbook(QWidget *parent) :
    QblDesktopContent(QblDesktopContent::ADDRESSBOOK, parent)
{
    this->changed();    
    this->ui->btListBottom->setText("Add contact");
    this->ui->btListBottom->show();
    connect(this->ui->btListBottom, SIGNAL(clicked()), this, SLOT(onAddContactClicked()));
    
}

QblDesktopContentAddressbook::~QblDesktopContentAddressbook()
{
    delete item;
    return;
}

void QblDesktopContentAddressbook::changed()
{
    Qbl *qbl;
    std::list<QblJsonMainConfigIdentity *> list;
    std::list<QblJsonMainConfigIdentity *>::iterator iterator;


    /** TODO delete old content */
    /* create contakt list */
    qbl = Qbl::getInstance();
    if (qbl == NULL) {
        exit(0);
    }
    list = qbl->getConfig()->getIdentities()->getList();
    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        item = new QblDesktopAddressIdentity(*iterator, this->wdList);

        connect(item, SIGNAL(collapsedClicked()), this, SLOT(listResized()));
        connect(item, SIGNAL(addressChanged(QblJsonMainConfigContact*)),
                this, SLOT(onAddressChanged(QblJsonMainConfigContact*)));
        connect(item,
                SIGNAL(addressClicked(QblJsonMainConfigIdentity*,
                                      QblJsonMainConfigContact*)),
                this,
                SLOT(onAddressClicked(QblJsonMainConfigIdentity*,
                                      QblJsonMainConfigContact*)));

        this->identityList.push_back(item);
    }
    this->sortIdentitiesByAlias();
    this->listResized();
    return;
}

void QblDesktopContentAddressbook::sortIdentitiesByAlias() {
    this->identityList.sort(QblDesktopAddressIdentity::compareAlias);
}

void QblDesktopContentAddressbook::resizeEvent(QResizeEvent *event)
{
    QblDesktopContent::resizeEvent(event);


    return;
}

void QblDesktopContentAddressbook::onListIdentityClicked(int id, bool collapse)
{
    return;
}

void QblDesktopContentAddressbook::listResized()
{
    std::list<QblDesktopAddressIdentity*>::iterator iterator;
    int height = 0;

    for (iterator = this->identityList.begin();
         iterator != this->identityList.end(); iterator++) {
        (*iterator)->setGeometry(0, height, (*iterator)->width(), (*iterator)->height());
        height += (*iterator)->height();
    }

    this->wdList->setMaximumSize(this->ui->frAddressList->width(), height);
    this->wdList->setMinimumSize(this->ui->frAddressList->width(), height);
    this->ui->saAddressList->setWidget(this->wdList);
    

    return;
}

void QblDesktopContentAddressbook::onAddressChanged(QblJsonMainConfigContact *contact)
{
    std::list<QblDesktopAddressIdentity*>::iterator iterator;

    if (this->client->getContentChanged() == false) {
        for (iterator = this->identityList.begin();
             iterator != this->identityList.end(); iterator++) {
            (*iterator)->setActive(contact);
        }
    }


    return;
}

void QblDesktopContentAddressbook::onAddressClicked(QblJsonMainConfigIdentity *identity,
                                         QblJsonMainConfigContact *contact)
{
    emit(contactClicked(identity, contact));

    return;
}

void QblDesktopContentAddressbook::onAddContactClicked()
{
    QblDesktopAddNewContact *addContact = new QblDesktopAddNewContact(this->identityList, this);
    addContact->setAttribute(Qt::WA_DeleteOnClose, true);
    addContact->show();
    
    return;
}
