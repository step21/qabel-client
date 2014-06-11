/**
 * @file		qbl-desktop-client.cpp
 * @brief		Main class of the Qabel client (Implementation)
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

#include <list>
using namespace std;

#include <stdio.h>

#include "qbl-desktop-client.h"
#include "ui_qbl-desktop-client.h"
#include "qbl-desktop-settings.h"

QblDesktopClient::QblDesktopClient(QblCss::os os, QWidget *widget) :
    QDialog(widget), ui(new Ui::QblDesktopClient),
    contentType(QblContent::NONE), content(NULL), addressbook(NULL),
    chat(NULL), settings(NULL), file(NULL)
{
    this->qbl = Qbl::getInstance(this);

    this->client = QblClient::getInstance(os, this->qbl);

    this->ui->setupUi(this);

    this->initCallbackListener();
    this->initSystemTrayAction();
    this->initSystemTray();
    this->initTopInfoList();

    this->addIcon();
    this->showStuff();

    // hide the info and comment button
    this->set_btTopComment_visible(false);
    this->set_btTopInfo_visible(false);

    this->setStyleSheet(this->client->getCss().getStyleSheet());

    // TODO read height and width from configuration
    this->resize(800, 600);
    this->createContent(QblContent::CHAT);

    return;
}

QblDesktopClient::~QblDesktopClient()
{
    if (this->addressbook != NULL) {
        delete (this->addressbook);
    }
    if (this->chat != NULL) {
        delete (this->chat);
    }
    if (this->file != NULL) {
        delete (this->file);
    }
    if (this->settings != NULL) {
        delete (this->settings);
    }

    delete (this->ui);

    return;
}

void QblDesktopClient::setVisible(bool visible)
{
    acMinimize->setEnabled(visible);
    acRestore->setEnabled(isMaximized() || !visible);
    QDialog::setVisible(visible);
}

void QblDesktopClient::newMessageReceived(QblMessage *message)
{
    emit(updateSystemTray(message));

    return;
}

void QblDesktopClient::resizeEvent(QResizeEvent *)
{
    int frContent_height;
    int topLeftCorner_width;
    frContent_height =
            this->height() - (this->ui->frTopBox->height()
                              + this->ui->frBottomBox->height());
    topLeftCorner_width = this->ui->lbTopLeftCorner->width();

    this->ui->frTopBox->resize(this->width() - topLeftCorner_width,
                               this->ui->frTopBox->height());

    this->ui->frBottomBox->setGeometry(
                0, this->height() - this->ui->frBottomBox->height(),
                this->width(),
                this->ui->frBottomBox->height()
                );

    this->ui->frContent->resize(this->width(), frContent_height);
    if (this->content != NULL) {
        this->content->resize(this->width(), frContent_height);
    }

    return;
}

void QblDesktopClient::initSystemTrayAction()
{
    acMinimize = new QAction(tr("Mi&nimize"), this);
    connect(acMinimize, SIGNAL(triggered()), this, SLOT(hide()));

    acRestore = new QAction(tr("&Restore"), this);
    connect(acRestore, SIGNAL(triggered()), this, SLOT(showNormal()));

    acQuit = new QAction(tr("&Quit"), this);
    connect(acQuit, SIGNAL(triggered()), qApp, SLOT(quit()));

    return;
}

void QblDesktopClient::initSystemTray()
{
    systemTrayMenu = new QMenu(this);
    systemTrayMenu->addAction(acMinimize);
    systemTrayMenu->addAction(acRestore);
    systemTrayMenu->addSeparator();
    systemTrayMenu->addAction(acQuit);

    systemTray = new QSystemTrayIcon(this);
    systemTray->setContextMenu(systemTrayMenu);

    connect(this, SIGNAL(updateSystemTray(QblMessage *)), this,
            SLOT(systemTrayIsUpdated(QblMessage *)));

    return;
}

void QblDesktopClient::initCallbackListener()
{
    this->chat = new QblDesktopChat(this->ui->frContent);
    this->qbl->setChatReceiveListener((IQblChatReceive *)this->chat);

    return;
}

void QblDesktopClient::addIcon()
{
    QIcon icon;

    icon = QIcon(":/images/qabel-logo-icon.png");
    systemTray->setIcon(icon);
    this->setWindowIcon(icon);

    return;
}

void QblDesktopClient::showStuff()
{
    systemTray->show();

    return;
}

bool QblDesktopClient::is_btTopInfo_visible()
{
    return (this->ui->btTopInfo->isVisible());
}

void QblDesktopClient::set_btTopInfo_visible(bool visible)
{
    int width, height;

    if (visible == true) {
        width = height = 0;
    } else {
        width = this->ui->btTopInfo->size().width();
        height = this->ui->btTopInfo->size().height();
    }
    this->ui->hsTopInfo->changeSize(width, height);
    this->ui->btTopInfo->setVisible(visible);

    return;
}

bool QblDesktopClient::is_btTopComment_visible()
{
    return (this->ui->btTopComment->isVisible());
}

void QblDesktopClient::set_btTopComment_visible(bool visible)
{
    this->ui->btTopComment->setVisible(visible);

    return;
}

void QblDesktopClient::createContent(QblContent::contentType type)
{
    QblContent *oldContent;

    if (type == this->contentType) {
        return;
    }

    oldContent = this->content;

    switch (type) {
    case QblContent::NONE:
        this->content = NULL;
        break;
    case QblContent::ADDRESSBOOK:
        this->content = this->addressbook;
        this->ui->btTopChat->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopAddressbook->setStyleSheet("QPushButton { color : black; }");
        this->ui->btTopFolder->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopSettings->setStyleSheet("QPushButton { color : white; }");
        break;
    case QblContent::CHAT:
        this->chat->changed();
        this->content = this->chat;
        this->ui->btTopChat->setStyleSheet("QPushButton { color : black; }");
        this->ui->btTopAddressbook->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopFolder->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopSettings->setStyleSheet("QPushButton { color : white; }");
        break;
    case QblContent::FILE:
        this->content = this->file;
        this->ui->btTopChat->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopAddressbook->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopFolder->setStyleSheet("QPushButton { color : black; }");
        this->ui->btTopSettings->setStyleSheet("QPushButton { color : white; }");
        break;
    case QblContent::SETTINGS:
        this->content = this->settings;
        this->ui->btTopChat->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopAddressbook->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopFolder->setStyleSheet("QPushButton { color : white; }");
        this->ui->btTopSettings->setStyleSheet("QPushButton { color : black; }");
        break;
    }

    if (this->content != NULL) {
        int height;

        height =
                this->height() - this->ui->frTopBox->height()
                - this->ui->frBottomBox->height();
        this->content->setGeometry(0, 0, this->width(), height);
        this->content->show();

        this->contentType = this->content->getType();
    }

    if (oldContent != NULL) {
        if (this->content != oldContent) {
            oldContent->hide();
        }
    }

    return;
}

void QblDesktopClient::on_btSendClicked()
{
    QString header;

    header = tr("Chat");

    return;
}

void QblDesktopClient::on_btTopInfo_clicked()
{
    this->topInfoList->setGeometry(this->ui->frTopBox->x(),
                                   this->ui->frTopBox->height(), 300, 100);

    this->topInfoList->show();
    return;
}

void QblDesktopClient::on_btTopComment_clicked()
{
    return;
}

void QblDesktopClient::on_btTopAddressbook_clicked()
{
    if (this->client->getContentChanged() == false) {
        if (this->addressbook == NULL) {
            this->addressbook = new QblDesktopAddressbook(this->ui->frContent);
        }

        this->createContent(QblContent::ADDRESSBOOK);
    }

    return;
}

void QblDesktopClient::on_btTopChat_clicked()
{
    if (this->client->getContentChanged() == false) {
        if(this->chat == NULL) {
            this->chat = new QblDesktopChat(this->ui->frContent);
        }

        this->createContent(QblContent::CHAT);
    }

    return;
}

void QblDesktopClient::on_btTopFolder_clicked()
{
    if (this->client->getContentChanged() == false) {
        if(this->file == NULL) {
            this->file = new QblDesktopFile(this->ui->frContent);
        }
        this->createContent(QblContent::FILE);

    }

    return;
}

void QblDesktopClient::on_btTopSettings_clicked()
{
    if (this->client->getContentChanged() == false) {
        if (this->settings == NULL) {
            this->settings = new QblDesktopSettings(this->ui->frContent);
        }
        this->createContent(QblContent::SETTINGS);
    }

    return;
}

void QblDesktopClient::on_messageReceived()
{
    this->topInfoList->addToInfoList();
    this->set_btTopInfo_visible(true);

    return;
}

void QblDesktopClient::initTopInfoList()
{
    this->topInfoList = new QblDesktopTopInfoList(this);
    this->topInfoList->hide();
    
    return;
}

void QblDesktopClient::systemTrayIsUpdated(QblMessage *message)
{
    this->systemTray->showMessage(
                QString("Message type: %1").arg(message->getContentType()),
                QString("Content"));
    this->set_btTopInfo_visible(true);

    return;
}
