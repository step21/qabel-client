/**
 * @file		qbl-desktop-address-itentity.cpp
 * @brief		Class which show and handle the identity and the contacts of
 *              the identity (Implementation)
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

#include "qbl-json-main-config-contact-array.h"

#include "qbl-client.h"
#include "qbl-desktop-address-identity.h"

QblDesktopAddressIdentity::QblDesktopAddressIdentity(
        QblJsonMainConfigIdentity *obj, QWidget *parent) :
        QWidget(parent), obj(obj)
{
    QblClient *client = QblClient::getInstance();
    std::list<QblJsonMainConfigContact *>::iterator contactsIterator;
    std::list<QblDesktopListAddressRow *>::iterator itemsIterator;

    this->layout = new QVBoxLayout(this);
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    this->layout->setContentsMargins(0, 0, 0, 0);

    this->identity = new QblDesktopListIdentity(obj, true);
    this->identity->setStyleSheet(
            client->getCss().getStyleSheet("list-identity"));
    this->identity->setText(QString::fromStdString(obj->getAlias()));
    this->layout->addWidget(this->identity, 0, Qt::AlignTop);

    connect(this->identity, SIGNAL(collapsed(bool)), this,
            SLOT(onListIdentityClicked(bool)));

    this->contacts = client->getLibrary()->getConfig()->getContacts()->getList();
    for (contactsIterator = this->contacts.begin(); contactsIterator != this->contacts.end();
         contactsIterator++) {
        if (! (*contactsIterator)->getMyId().compare(obj->getPublicKey())) {
            QblDesktopListAddressRow *item;

            item = new QblDesktopListAddressRow(*contactsIterator, this->contactCount++, this);
            connect(item, SIGNAL(changed(QblJsonMainConfigContact*)),
                    this, SLOT(onListRowChanged(QblJsonMainConfigContact*)));
            connect(item, SIGNAL(clicked(QblJsonMainConfigContact*)),
                    this, SLOT(onListRowClicked(QblJsonMainConfigContact*)));
            items.push_back(item);
        }
    }
    this->sortContactsByAlias();
    for (itemsIterator = this->items.begin(); itemsIterator != this->items.end(); itemsIterator++) {
        this->layout->addWidget((*itemsIterator));
    }
    this->setHeight();

    return;
}

QblDesktopAddressIdentity::~QblDesktopAddressIdentity()
{
    return;
}

void QblDesktopAddressIdentity::setActive(QblJsonMainConfigContact *contact)
{
    std::list<QblDesktopListAddressRow *>::iterator iterator;

    for (iterator = this->items.begin(); iterator != this->items.end();
         iterator++) {
        (*iterator)->setActive(contact);
    }

    return;
}


bool QblDesktopAddressIdentity::compareAlias(QblDesktopAddressIdentity* first, QblDesktopAddressIdentity* second) {
    unsigned int i = 0;
    std::string firstNick = first->getAlias();
    std::string secondNick = second->getAlias();
    while ( (i<firstNick.length()) && (i<secondNick.length())) {
        if (tolower(firstNick[i])<tolower(secondNick[i])) {
            return true;
        }
        else if (tolower(firstNick[i])>tolower(secondNick[i])) {
            return false;
        }
        ++i;
    }
    return ( firstNick.length() < secondNick.length());
}

std::string QblDesktopAddressIdentity::getAlias() {
    return this->obj->getAlias();
}

void QblDesktopAddressIdentity::resizeEvent(QResizeEvent */*event*/)
{
    this->setHeight();

    return;
}

void QblDesktopAddressIdentity::setHeight()
{
    int height;
    std::list<QblDesktopListAddressRow *>::iterator iterator;

    height = this->identity->height();
    if (this->identity->getCollapse() == false) {
        iterator = this->items.begin();
        height += this->items.size() * (*iterator)->maximumHeight();
    }

    this->resize(this->identity->width(), height);

    return;
}

void QblDesktopAddressIdentity::onListIdentityClicked(bool /*collapse*/)
{
    this->setHeight();
    emit(collapsedClicked());

    return;
}

void QblDesktopAddressIdentity::onListRowChanged(
        QblJsonMainConfigContact *contact)
{
    emit(addressChanged(contact));

    return;
}

void QblDesktopAddressIdentity::onListRowClicked(
        QblJsonMainConfigContact *contact)
{
    emit(addressClicked(this->obj, contact));

    return;
}

void QblDesktopAddressIdentity::sortContactsByAlias() {
    this->items.sort(QblDesktopListAddressRow::compareAlias);
}

const std::string& QblDesktopAddressIdentity::getPublicKey()
{
    return this->obj->getPublicKey();
}

void QblDesktopAddressIdentity::addContact(QblJsonMainConfigContact *contact)
{
    std::list<QblDesktopListAddressRow *>::iterator itemsIterator;
    bool isNew = true;
    for(itemsIterator = this->items.begin(); itemsIterator != this->items.end(); itemsIterator++) {
        if((*itemsIterator)->isEqual(contact)) {
            isNew = false;
        }
    }
    if(isNew) {
        QblDesktopListAddressRow *item = new QblDesktopListAddressRow(contact, this->contactCount++, this);
        connect(item, SIGNAL(changed(QblJsonMainConfigContact*)),
                this, SLOT(onListRowChanged(QblJsonMainConfigContact*)));
        connect(item, SIGNAL(clicked(QblJsonMainConfigContact*)),
                this, SLOT(onListRowClicked(QblJsonMainConfigContact*)));
        items.push_back(item);
    }
    delete(this->layout);
    this->layout = new QVBoxLayout(this);
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    this->layout->setContentsMargins(0, 0, 0, 0);
    
    this->layout->addWidget(this->identity, 0, Qt::AlignTop);

    connect(this->identity, SIGNAL(collapsed(bool)), this,
            SLOT(onListIdentityClicked(bool)));
    
    this->sortContactsByAlias();
    for (itemsIterator = this->items.begin(); itemsIterator != this->items.end(); itemsIterator++) {
        this->layout->addWidget((*itemsIterator));
    }
    this->setHeight();
    this->identity->setCollapse(true);
    
}

