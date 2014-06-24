/**
 * @file		qbl-desktop-addressbook.cpp
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

#include "qbl-desktop-addressbook.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-list-identity.h"

#include "qbl.h"
#include "config/qbl-json-main-config-identity.h"
#include "config/qbl-json-main-config-identity-array.h"


QblDesktopAddressbook::QblDesktopAddressbook(QWidget *parent) :
    QblDesktopContentAddressbook(parent)
{
    connect(this,
            SIGNAL(contactClicked(QblJsonMainConfigIdentity*,
                                  QblJsonMainConfigContact*)),
            this,
            SLOT(onContactClicked(QblJsonMainConfigIdentity*,
                                  QblJsonMainConfigContact*)));

    return;
}

QblDesktopAddressbook::~QblDesktopAddressbook()
{
    if(this->content != NULL) {
        delete (this->content);
    }
    
    return;
}

void QblDesktopAddressbook::resizeEvent(QResizeEvent *event)
{
    QblDesktopContentAddressbook::resizeEvent(event);
    
    if(this->content != NULL) {
        this->ui->frContentField->resize(event->size().width() -
                                         this->ui->frAddressList->width(),
                                         event->size().height());
        this->content->resize(this->ui->frContentField->width(),
                              this->ui->frContentField->height());
    }
    return;
}

void QblDesktopAddressbook::onContactClicked(
        QblJsonMainConfigIdentity * identity, QblJsonMainConfigContact *contact)
{
    QblDesktopAddressbookContent *oldContent;
    oldContent = this->content;
    
    this->content = new QblDesktopAddressbookContent(identity, contact, this->ui->frContentField);
    this->content->resize(this->ui->frContentField->width(), this->ui->frContentField->height());
    this->content->show();
    
    if(oldContent != NULL) {
        oldContent->hide();
        delete oldContent;
    }
    
    return;
}
