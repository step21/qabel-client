/**
 * @file		qbl-desktop-chat-content.cpp
 * @brief		Chat windows for the desktop application (Implementation)
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

#include <QFileDialog>
#include <QScrollBar>

#include "qbl-config-file.h"
#include "qbl-json-chat-message.h"
#include "qbl-chat-message-send.h"
#include "qbl-chat-history.h"


#include "qbl-desktop-chat-content.h"
#include "ui_qbl-desktop-chat-content.h"
#include "qbl-desktop-chat-ballon-me.h"
#include "qbl-desktop-chat-ballon-other.h"

QblDesktopChatContent::QblDesktopChatContent(
        QblJsonMainConfigIdentity *identity,
        QblJsonMainConfigContact *contact,
        QWidget *parent) :
    QWidget(parent), IQblChatSend(), ui(new Ui::QblDesktopChatContent),
    identity(identity), contact(contact)
{
    this->ui->setupUi(this);
    this->client = QblClient::getInstance();

    this->wdMessages = new QWidget(this->ui->saMessages);
    this->ui->saMessages->setWidgetResizable(true); //set to true;remove because ballon resize
    this->ui->saMessages->setWidget(this->wdMessages);

    this->setNames();

    this->ui->teMessage->setFocus();

    return;
}

QblDesktopChatContent::~QblDesktopChatContent()
{
    delete (this->ui);

    return;
}

QblJsonMainConfigIdentity *QblDesktopChatContent::getSender()
{
    return (this->identity);
}

QblJsonMainConfigContact *QblDesktopChatContent::getRecipient()
{
    return (this->contact);
}

std::list<QblJsonChatMessageComplete> QblDesktopChatContent::getHistory()
{
    return (this->history);
}

void QblDesktopChatContent::setHistory(std::list<QblJsonChatMessageComplete> history)
{
    std::list<QblJsonChatMessageComplete>::iterator iterator;
    QWidget *ballon;

    while (this->messageList.size() > 0) {
        ballon = this->messageList.front();
        this->messageList.pop_front();
        ballon->hide();
        
        //TODO: destroy ballon
    }
    
    this->history = history;
    int counter_y = this->ballonMargin;
    
    
    int ballonMe_LeftMargin = this->ui->saMessages->width() - this->style()->pixelMetric(QStyle::PM_ScrollBarExtent) - this->ballonMargin;
    
    for (iterator = this->history.begin(); iterator != this->history.end();
         iterator++) {

        if (! this->getSender()->getAlias().compare(iterator->getSender())) {
            ballon = new QblDesktopChatBallonMe(*iterator, this->wdMessages);
            ballon->setGeometry(ballonMe_LeftMargin - ballon->width(),counter_y,ballon->width(),ballon->height());
            
        } else {
            ballon = new QblDesktopChatBallonOther(*iterator, this->wdMessages);
            ballon->setGeometry(this->ballonMargin, counter_y, ballon->width(),ballon->height());
        }
        counter_y += ballon->height() + this->ballonMargin;
        ballon->show();
        this->messageList.push_back(ballon);
        ballon=NULL;
    }

    this->wdMessages->setMinimumSize(800, counter_y + this->ballonMargin);
    QScrollBar *scrollBar = this->ui->saMessages->verticalScrollBar();
    scrollBar->setValue(scrollBar->maximum());

    return;
}

void QblDesktopChatContent::messageSend(bool done)
{    
    return;
}

void QblDesktopChatContent::resizeEvent(QResizeEvent *event)
{
    int iconWidth, bottomHeight, teMessage_margin;
    teMessage_margin = 10;
    iconWidth = this->ui->frContentTopBox->height()/3*2;
    bottomHeight = this->ui->wgBottom->height();

    // set top content
    this->ui->frContentTopBox->resize(event->size().width(),
                                      this->ui->frContentTopBox->height());
    this->ui->lbMeImage->resize(iconWidth, iconWidth);
    this->ui->lbOtherImage->resize(iconWidth, iconWidth);

    // set scroll area
    this->ui->saMessages->setGeometry(0,
                                      this->ui->frContentTopBox->height(),
                                      event->size().width(),
                                      event->size().height() - 
                                      this->ui->frContentTopBox->height() - 
                                      this->ui->frContentBottomBox->height() - 
                                      bottomHeight);

    // set bottom content
    this->ui->frContentBottomBox->setGeometry(0,
                                              event->size().height() -
                                              this->ui->frContentBottomBox->height(),
                                              event->size().width(),
                                              this->ui->frContentBottomBox->height());
    
    this->ui->wgBottom->setGeometry(0,
                                    this->ui->saMessages->y() + this->ui->saMessages->height(),
                                    event->size().width(),
                                    bottomHeight);
    
    this->ui->btSend->setGeometry(
                event->size().width() - this->ui->btSend->width(),
                this->ui->btSend->y(), this->ui->btSend->width(),
                this->ui->btSend->height());
    
    this->ui->teMessage->setGeometry(teMessage_margin,
                                     teMessage_margin,
                                     this->ui->wgBottom->width() - teMessage_margin,
                                     this->ui->wgBottom->height() - teMessage_margin
                                     );
    //resize and place ballons
    std::list<QWidget *>::iterator iterator;

    int ballonMe_LeftMargin = this->ui->saMessages->width() - this->style()->pixelMetric(QStyle::PM_ScrollBarExtent) - this->ballonMargin;
    int counter_y=0;
    
    for (iterator = this->messageList.begin(); iterator != this->messageList.end();iterator++) {
        
        QblDesktopChatBallon *ballon = (QblDesktopChatBallon *)(*iterator);
        if(ballon->isBallonMe()) {
            (*iterator)->setGeometry(ballonMe_LeftMargin-(*iterator)->width(),
                                     counter_y,
                                     (*iterator)->width(),
                                     (*iterator)->height());
            
        }
        counter_y += (*iterator)->height() + this->ballonMargin;
    }

    return;
}

void QblDesktopChatContent::showEvent(QShowEvent * /*event*/)
{
    this->client->getLibrary()->getChatHistory()->addContact(contact);

    return;
}

void QblDesktopChatContent::hideEvent(QHideEvent * /*event*/)
{
    this->client->getLibrary()->getChatHistory()->removeContact(contact);

    return;
}

void QblDesktopChatContent::keyReleaseEvent(QKeyEvent *event)
{
    if (this->ui->teMessage->hasFocus()) {
        if (event->key() == Qt::Key_Return) {
            if (! (event->modifiers() & Qt::ShiftModifier)
                    && ! (event->modifiers() & Qt::ControlModifier)) {
                QString msg;

                msg = this->ui->teMessage->toPlainText();
                msg.resize(msg.length() - 1);
                this->ui->teMessage->setPlainText(msg);

                this->on_btSend_clicked();
            }
        }
    }

    return;
}

void QblDesktopChatContent::setNames()
{
    this->ui->lbMe->setText(
                QString::fromStdString(this->identity->getAlias()));
    this->ui->lbOther->setText(
                QString::fromStdString(this->contact->getAlias()));

    return;
}

void QblDesktopChatContent::on_btEmoticons_clicked()
{
    return;
}

void QblDesktopChatContent::on_btSendFile_clicked()
{
    QString fileName;

    fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                            QblConfigFile::getHomeDir());

    if (fileName != NULL) {
        QblChatMessageSend *message;
        QblJsonChat chat(this->identity->getAlias(), fileName.toStdString(),
                         "");

        message = new QblChatMessageSend(this, chat, this->contact);
        message->addMessageToQueue();
    }

    return;
}

void QblDesktopChatContent::on_btSend_clicked()
{
    QblChatMessageSend *message;
    time_t now;

    now = time(NULL);

    QblJsonChatMessage chat(this->identity->getAlias(),
                     this->ui->teMessage->toPlainText().toStdString(), now);
    message = new QblChatMessageSend(this, chat, this->contact);
    message->addMessageToQueue();

    this->ui->teMessage->setPlainText("");
    return;
}

void QblDesktopChatContent::historyIsUpdated(std::list<QblJsonChatMessageComplete> history) {
    std::list<QblJsonChatMessageComplete>::iterator iterator = history.end();
    iterator--;
    if(! this->getSender()->getAlias().compare(iterator->getSender())) {
        // TODO: notify;
    }
    this->setHistory(history);
}
