/**
 * @file		qbl-desktop-list-identity.cpp
 * @brief		List element for the identity (Implementation)
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

#include "qbl-desktop-list-identity.h"
#include "ui_qbl-desktop-list-identity.h"

QblDesktopListIdentity::QblDesktopListIdentity(
        QblJsonMainConfigIdentity *identity, bool collapse, QWidget *parent) :
        QblDesktopListItem(obj, parent), ui(new Ui::QblDesktopListIdentity),
        collapse(collapse)
{
    this->ui->setupUi(this);

    return;
}

QblDesktopListIdentity::~QblDesktopListIdentity()
{

    return;
}

void QblDesktopListIdentity::setText(QString text)
{
    this->ui->lbIdentity->setText(text);

    return;
}

QString QblDesktopListIdentity::text()
{
    return (this->ui->lbIdentity->text());
}

bool QblDesktopListIdentity::getCollapse()
{
    return (this->collapse);
}

void QblDesktopListIdentity::setCollapse(bool collapse)
{
    this->collapse = collapse;
    this->on_btCollapse_clicked();

    return;
}

void QblDesktopListIdentity::on_btCollapse_clicked()
{
    QIcon icon;

    if (collapse == true) {
        icon = QIcon(":/images/arrow-down.png");
    } else {
        icon = QIcon(":/images/arrow-right.png");
    }
    this->ui->btCollapse->setIcon(icon);
    this->ui->btCollapse->repaint();

    this->collapse = !this->collapse;

    emit(collapsed(collapse));

    return;
}
