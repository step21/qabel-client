/**
 * @file		qbl-desktop-chat-ballon-other.cpp
 * @brief		Chat message ballon for other (Implementation)
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

#include <QDateTime>

#include "qbl-desktop-chat-ballon-other.h"
#include "ui_qbl-desktop-chat-ballon-other.h"

QblDesktopChatBallonOther::QblDesktopChatBallonOther(
        QblJsonChatMessageComplete history, QWidget *parent) :
    QblDesktopChatBallon(history, parent), ui(new Ui::QblDesktopChatBallonOther)
{
    this->ui->setupUi(this);

    this->setText();

    return;
}

QblDesktopChatBallonOther::~QblDesktopChatBallonOther()
{
    delete (this->ui);

    return;
}

void QblDesktopChatBallonOther::setText()
{
    this->ui->lbMessage->setText(this->getMessage());
    this->ui->lbTime->setText(this->getMessageDate());

    return;
}

bool QblDesktopChatBallonOther::isBallonMe() {
    return false;
}
