/**
 * @file		qbl-desktop-content.h
 * @brief		Address book for the desktop application (Header file)
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

#ifndef __QBL_DESKTOP_CONTENT_H__
#define __QBL_DESKTOP_CONTENT_H__

#include <QFrame>
#include <QLayout>

#include "qbl-content.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-address-identity.h"
#include "qbl-client.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the address book
 */
class QblDesktopContent;
}

/**
 * Class QblDesktopContent: Address book for the desktop application
 * @brief The QblDesktopContent class
 */
class QblDesktopContent: public QblContent {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopContent
     * @param parent
     */
    explicit QblDesktopContent(QblContent::contentType type = QblContent::NONE,
                               QWidget *parent = 0);
    virtual ~QblDesktopContent();

    /**
     * This function have to call when there are changes on the address book
     * @todo delete old content
     * @brief changed
     */
    virtual void changed();
    /**
     * Set the height of the header
     * @brief setHeaderHeight
     * @param height New header height (default: 60)
     */
    void setHeaderHeight(int height = 60);

public slots:

protected:
    Ui::QblDesktopContent *ui;      /**< Object handle the UI stuff */

    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    virtual void resizeEvent(QResizeEvent *event);
    QWidget *wdList;                /**< Widget for the contact list */
    QblClient *client;              /**< QblClient object */


    int headerHeight;
private:
               /**< Height of the top widget */

private slots:



signals:
    //void contactChanged(QblJsonMainConfigContact contact);
    void contactClicked(QblJsonMainConfigIdentity *identity,
                        QblJsonMainConfigContact *contact);
    void preferencesClicked();
    void dropServersClicked();
};

#endif // __QBL_DESKTOP_CONTENT_H__
