/**
 * @file		qbl-desktop-addressbook-content.h
 * @brief		Addressbook windows for the desktop application (Header)
 * @author		Fabian Träger <traeger@praemandatum.de>
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

#ifndef QBLDESKTOPADDRESSBOOKCONTENT_H
#define QBLDESKTOPADDRESSBOOKCONTENT_H

#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-contact.h"

#include <QWidget>
#include <QResizeEvent>

namespace Ui {
class QblDesktopAddressbookContent;
}

class QblDesktopAddressbookContent : public QWidget
{
    Q_OBJECT
    
public:
    explicit QblDesktopAddressbookContent(QblJsonMainConfigIdentity *identity,
                                          QblJsonMainConfigContact *contact,QWidget *parent = 0);
    ~QblDesktopAddressbookContent();
    
protected:
    void resizeEvent(QResizeEvent *event);
    
private slots:
    void on_btEditContact_clicked();
    
    void on_btStoreChanges_clicked();
    
    void on_btCancel_clicked();
    
    void on_btRemove_clicked();
    
private:
    Ui::QblDesktopAddressbookContent *ui; /**< Object handle the UI stuff */
    QblJsonMainConfigIdentity *identity; /**< My ID for the contact */
    QblJsonMainConfigContact *contact; /**< Contact that is shown */
    
    /**
     * Init fields and images of the contact
     * @todo images
     * @brief initContent
     */
    void initContent();
    /**
     * Init line and text edits for editing
     * @brief initEdits
     */
    void initEdits();
    /**
     * Store the changes made in edit mode in the main config
     * @brief storeChanges
     */
    void storeChanges();
};

#endif // QBLDESKTOPADDRESSBOOKCONTENT_H
