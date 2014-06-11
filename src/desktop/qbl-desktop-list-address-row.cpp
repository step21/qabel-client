/**
 * @file		qbl-desktop-list-address-row.cpp
 * @brief		One address list element (Implementation)
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

#include "qbl-desktop-list-address-row.h"
#include "ui_qbl-desktop-list-row.h"

QblDesktopListAddressRow::QblDesktopListAddressRow(
        QblJsonMainConfigContact *contact, int id, QWidget *parent) :
        QblDesktopListItem(contact, parent),
        ui(new Ui::QblDesktopListRow), contact(contact), id(id)
{
    this->ui->setupUi(this);

    this->client = QblClient::getInstance();

    this->setText(QString::fromStdString(
                      ((QblJsonMainConfigContact *)this->obj)->getAlias()));

    this->setCss();

    return;
}

QblDesktopListAddressRow::~QblDesktopListAddressRow()
{
    delete (this->ui);
}

void QblDesktopListAddressRow::setText(QString text)
{
    this->ui->lbRow->setText(text);

    return;
}

QString QblDesktopListAddressRow::text()
{
    return (this->ui->lbRow->text());
}

void QblDesktopListAddressRow::setActive(QblJsonMainConfigContact *contact)
{
    if (QblJsonObject::isUuidEqual(this->obj->compare(contact)) == TRUE) {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-active"));
        emit(clicked((QblJsonMainConfigContact *)this->obj));
    } else {
        this->setCss();
    }

    return;
}

void QblDesktopListAddressRow::mouseReleaseEvent(QMouseEvent* /*event*/)
{
    emit(changed((QblJsonMainConfigContact *)this->obj));

    return;
}

void QblDesktopListAddressRow::setCss()
{
    if ((id % 2) == 0) {
        this->setStyleSheet(this->client->getCss().getStyleSheet("list-row"));
    } else {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-another-row"));
    }

    return;
}

std::string QblDesktopListAddressRow::getAlias() {
    return ((QblJsonMainConfigContact *) this->obj)->getAlias();
}

bool QblDesktopListAddressRow::compareAlias(QblDesktopListAddressRow* first, QblDesktopListAddressRow* second) {
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

bool QblDesktopListAddressRow::isEqual(QblJsonMainConfigContact *contact)
{
    return(this->contact->getUuid() == contact->getUuid());
}
