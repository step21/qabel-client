/**
 * @file		qbl-desktop-chat-content.h
 * @brief		Chat windows for the desktop application (Header)
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

#ifndef __QBL_DESKTOP_CHAT_CONTENT_H__
#define __QBL_DESKTOP_CHAT_CONTENT_H__

#include "iqbl-chat-send.h"

#include "qbl-json-object.h"
#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-contact.h"

#include <qbl-client.h>

#include <QWidget>
#include <QResizeEvent>

namespace Ui {
class QblDesktopChatContent;
}

class QblDesktopChatContent : public QWidget, IQblChatSend
{
    Q_OBJECT

public:
    explicit QblDesktopChatContent(QblJsonMainConfigIdentity *identity,
                                   QblJsonMainConfigContact *contact,
                                   QWidget *parent = 0);
    ~QblDesktopChatContent();

    /**
     * Get a sender identity
     * @brief getSender
     * @return Sender identity
     */
    QblJsonMainConfigIdentity *getSender();
    /**
     * Get a recipient identity
     * @brief getRecipient
     * @return Recipient identity
     */
    QblJsonMainConfigContact *getRecipient();
    /**
     * Get a chat history
     * @brief getHistory
     * @return Chat history
     */
    std::list<QblJsonChatMessageComplete> getHistory();
    /**
     * Set a new chat history
     * @brief setHistory
     * @param history New chat history
     */
    void setHistory(std::list<QblJsonChatMessageComplete> lastMessages);
    /**
     * Callback function to receive the last message add the the message list
     * @param message Last message
     */
    void messageSend(bool done);

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);
    /**
     * This event handler can be reimplemented in a subclass to receive
     * widget show events which are passed in the event parameter.
     * Non-spontaneous show events are sent to widgets immediately before
     * they are shown. The spontaneous show events of windows are delivered
     * afterwards.
     * @brief showEvent
     * @param event Show Event object
     */
    void showEvent(QShowEvent * event);
    /**
     * This event handler can be reimplemented in a subclass to receive widget
     * hide events. The event is passed in the event parameter.
     * Hide events are sent to widgets immediately after they have been hidden.
     * @brief hideEvent
     * @param event Hide event object
     */
    void hideEvent(QHideEvent * event);
    /**
     * This handler will called when a key will released
     * @brief keyReleaseEvent
     * @param event Key event object
     */
    void keyReleaseEvent(QKeyEvent *event);

private:
    Ui::QblDesktopChatContent *ui;  /**< Object handle the UI stuff */
    QblJsonMainConfigIdentity *identity; /**< Identity of the sender */
    QblJsonMainConfigContact *contact; /**< Identity of the recipent */
    std::list<QblJsonChatMessageComplete> history; /**< Chat history */
    QblClient *client;              /**< Client object */
    QWidget *wdMessages;            /**< Widget which show the history */
    std::list<QWidget *> messageList; /**< List of history ballon list */

    const int ballonMargin = 5;
    /**
     * Set names and images of the chat user
     * @todo images
     * @brief setNames
     */
    void setNames();

private slots:
    void on_btEmoticons_clicked();
    void on_btSendFile_clicked();
    void on_btSend_clicked();
    void historyIsUpdated(std::list<QblJsonChatMessageComplete> history);
    //void on_teMessage_textChanged();
};

#endif // __QBL_DESKTOP_CHAT_CONTENT_H__
