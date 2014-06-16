/**
 * @file		qbl-desktop-ballon-other.h
 * @brief		Chat message ballon for contact (Header file)
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

#ifndef __QBL_DESKTOP_CHAT_BALLON_OTHER_H__
#define __QBL_DESKTOP_CHAT_BALLON_OTHER_H__

#include <QWidget>

#include "chat/qbl-json-chat-message-complete.h"
#include "qbl-desktop-chat-ballon.h"

namespace Ui {
class QblDesktopChatBallonOther;
}

class QblDesktopChatBallonOther : public QblDesktopChatBallon
{
    Q_OBJECT

public:
    explicit QblDesktopChatBallonOther(QblJsonChatMessageComplete history,
            QWidget *parent = 0);
    ~QblDesktopChatBallonOther();

    void setText();
    
    virtual bool isBallonMe();

private:
    Ui::QblDesktopChatBallonOther *ui;
};

#endif // __QBL_DESKTOP_CHAT_BALLON_OTHER_H__
