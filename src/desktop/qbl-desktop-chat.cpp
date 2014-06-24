/**
 * @file		qbl-desktop-chat.cpp
 * @brief		Chat for the desktop application (Implementation)
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

#include "qbl-desktop-chat.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-list-identity.h"

#include "qbl.h"
#include "config/qbl-json-main-config-identity.h"
#include "config/qbl-json-main-config-identity-array.h"

QblDesktopChat::QblDesktopChat(QWidget *parent) :
        QblDesktopContentChat( parent), IQblChatReceive()
{
    this->content = NULL;

    connect(this,
            SIGNAL(contactClicked(QblJsonMainConfigIdentity*,
                                  QblJsonMainConfigContact*)),
            this,
            SLOT(onContactClicked(QblJsonMainConfigIdentity*,
                                  QblJsonMainConfigContact*)));
    connect(this,
            SIGNAL(addToTopInfo()),
            (QWidget *)(((QWidget*)(this->parent())))->parent(),
            SLOT(on_messageReceived()));
   
    return;
}

QblDesktopChat::~QblDesktopChat()
{
    if (this->content != NULL) {
        delete (this->content);
    }

    return;
}

void QblDesktopChat::messageReceived(std::string contact,
                                     std::list<QblJsonChatMessageComplete> history)
{   
    std::list<QblDesktopChatContent *>::iterator iterator;

    for (iterator = chats.begin(); iterator != chats.end(); iterator++) {
        if (! (*iterator)->getRecipient()->getAlias().compare(contact)) {
            emit(updateHistory(history));
        }
    }
    if(this->isVisible() == false) {
        emit(addToTopInfo());
    }

    return;
}

void QblDesktopChat::resizeEvent(QResizeEvent *event)
{
    QblDesktopContentChat::resizeEvent(event);

    if (this->content != NULL) {
        this->ui->frContentField->resize(event->size().width() -
                                         this->ui->frAddressList->width(),
                                         event->size().height());
        this->content->resize(this->ui->frContentField->width(),
                              this->ui->frContentField->height());
    }

    return;
}

void QblDesktopChat::onContactClicked(QblJsonMainConfigIdentity *identity,
                                      QblJsonMainConfigContact *contact)
{ 
    
    QblDesktopChatContent *oldContent;
    std::list<QblJsonChatMessageComplete> history;
    std::list<QblDesktopChatContent *>::iterator iterator;
    Qbl *qbl;

    oldContent = this->content;
    this->content = NULL;

    for (iterator = chats.begin(); iterator != chats.end(); iterator++) {
        uint8_t compareSender, compareRecipient;

        compareSender = (*iterator)->getSender()->compare(identity);
        compareRecipient = (*iterator)->getRecipient()->compare(contact);

        if (QblJsonObject::isUuidEqual(compareSender) &&
                QblJsonObject::isUuidEqual(compareRecipient)) {
            this->content = *iterator;
            break;
        }
    }

    if (this->content == NULL) {
        this->content =
                new QblDesktopChatContent(identity, contact,
                                          this->ui->frContentField);
        this->chats.push_back(this->content);
    }
    this->content->resize(this->ui->frContentField->width(), this->ui->frContentField->height());
    this->content->show();
    qRegisterMetaType<std::list<QblJsonChatMessageComplete>>("std::list<QblJsonChatMessageComplete>");
    connect(this, SIGNAL(updateHistory(std::list<QblJsonChatMessageComplete>)),
            this->content, SLOT(historyIsUpdated(std::list<QblJsonChatMessageComplete>)));
    
    qbl = Qbl::getInstance();
    history = qbl->getChatHistory()->getHistory(contact);
    this->content->setHistory(history);
    if (oldContent != NULL) {
        oldContent->hide();
    }

    return;
}
