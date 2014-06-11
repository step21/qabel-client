/**
 * @file		qbl-desktop-client.h
 * @brief		Main class of the Qabel client (Header file)
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

#ifndef __QBL_DESKTOP_CLIENT_H__
#define __QBL_DESKTOP_CLIENT_H__

#include <QDialog>
#include <QSystemTrayIcon>
#include <QMenu>

#include <iqbl.h>
#include <qbl.h>
#include <qbl-message.h>

#include "qbl-client.h"
#include "qbl-css.h"
#include "qbl-content.h"
#include "src/desktop/qbl-desktop-addressbook.h"
#include "src/desktop/qbl-desktop-chat.h"
#include "src/desktop/qbl-desktop-settings.h"
#include "src/desktop/qbl-desktop-file.h"
#include "src/desktop/qbl-desktop-topinfo-list.h"


/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the main desktop UI
 */
class QblDesktopClient;
}

/**
 * QblDesktopClient: class of the Qabel client
 * @brief The QblDesktopClient class
 */
class QblDesktopClient: public QDialog, IQbl {
    Q_OBJECT

public:
    /**
     * Constructor
     * @brief QblDesktopClient
     * @param os Used "Operation System"
     * @param widget Parent Qt widget
     */
    explicit QblDesktopClient(QblCss::os os = QblCss::DESKTOP,
                              QWidget *widget = 0);
    ~QblDesktopClient();

    /**
     * This function is called when the client window is changed
     * @brief setVisible
     * @param visible Current visible status
     */
    void setVisible(bool visible);

    /**
     * Callback function to receive the last message add the the message list
     * @todo not finish implemented
     * @param message Last message
     */
    void newMessageReceived(QblMessage *message);
    
public slots:
    /**
     * Handle when chat message is received
     * @brief on_chatMessageReceived
     */
    void on_messageReceived();

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);

private:
    Ui::QblDesktopClient *ui;       /**< Object handle the UI stuff */
    QblClient *client;              /**< QblClient object */

    QblContent::contentType contentType; /**< Current used widget in content
                                           area */
    QblContent *content;            /**< current content widget */
    QblDesktopAddressbook *addressbook; /**< Address book content object */
    QblDesktopChat *chat;           /**< Chat content object */
    QblDesktopSettings *settings;
    QblDesktopFile *file;
    QblDesktopTopInfoList *topInfoList;


    Qbl *qbl;                       /**< Library object */

    QAction *acMinimize;            /**< Action which handle the minimise the
                                      client UI */
    QAction *acRestore;             /**< Action which handle the restore the
                                      client UI */
    QAction *acQuit;                /**< Action which handle the quit the
                                      client UI */

    QSystemTrayIcon *systemTray;    /**< System tray object */
    QMenu *systemTrayMenu;          /**< System tray menu object */

    /**
     * Initialise the top info list
     * @brief initTopInfoList
     */
    void initTopInfoList();
    /**
     * Initialise the system tray action handler
     * @brief initSystemTrayAction
     */
    void initSystemTrayAction();
    /**
     * Initialise the system tray
     * @brief initSystemTray
     */
    void initSystemTray();
    /**
     * Initialise classes which have to handle callbacks
     * @brief initCallbackListener
     */
    void initCallbackListener();
    /**
     * Add icon on the UI elements
     * @brief addIcon
     */
    void addIcon();
    /**
     * Show the UI stuff on the desktop and system tray
     * @brief showStuff
     */
    void showStuff();
    /**
     * Is the info button in the top visibile
     * @brief is_btTopInfo_visible
     * @return true == visible
     */
    bool is_btTopInfo_visible();
    /**
     * Set the info button in the top visibile or hide it
     * @brief set_btTopInfo_visible
     * @param visible true => set the button visible
     */
    void set_btTopInfo_visible(bool visible);
    /**
     * Is the comment button in the top visibile
     * @brief is_btTopComment_visible
     * @return true == visible
     */
    bool is_btTopComment_visible();
    /**
     * Set the comment button in the top visibile or hide it
     * @brief set_btTopComment_visible
     * @param visible true => set the button visible
     */
    void set_btTopComment_visible(bool visible);
    /**
     * Create the main content
     * @brief createContent
     * @param type Content type to create
     */
    void createContent(QblContent::contentType type);

private slots:
    
    void on_btSendClicked();
    /**
     * Handle when info button in top menu is pressed
     * @brief on_btTopInfo_clicked
     */
    void on_btTopInfo_clicked();
    /**
     * Handle when comment button in top menu is pressed
     * @brief on_btTopComment_clicked
     */
    void on_btTopComment_clicked();
    /**
     * Handle when address book button in top menu is pressed
     * @brief on_btTopAddress_clicked
     */
    void on_btTopAddressbook_clicked();
    /**
     * Handle when chat button in top menu is pressed
     * @brief on_btTopChat_clicked
     */
    void on_btTopChat_clicked();
    /**
     * Handle when folder button in top menu is pressed
     * @brief on_btTopFolder_clicked
     */
    void on_btTopFolder_clicked();
    /**
     * Handle when setting button in top menu is pressed
     * @brief on_btTopSettings_clicked
     */
    void on_btTopSettings_clicked();
    void systemTrayIsUpdated(QblMessage *message);

signals:
    void updateSystemTray(QblMessage *message);

};

#endif // __QBL_DESKTOP_CLIENT_H__
