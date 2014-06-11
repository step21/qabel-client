/**
 * @file		qbl-desktop-ballon.cpp
 * @brief		Message ballon for the desktop application (Implementation)
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

#include "qbl-desktop-ballon.h"
#include "ui_qbl-desktop-ballon.h"

QblDesktopBallon::QblDesktopBallon(std::string message, time_t timestamp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QblDesktopBallon),
    message(message), timestamp(timestamp)
{
    this->ui->setupUi(this);

    this->setText();

    return;
}

QblDesktopBallon::~QblDesktopBallon()
{
    delete (this->ui);

    return;
}

void QblDesktopBallon::setText()
{
    this->ui->lbMessage->setText(QString::fromStdString(message));
    this->ui->lbTime->setText(QString("%1").arg(timestamp));

    return;
}
