/**
 * @file		qbl-desktop-address-itentity.h
 * @brief		Class which show and handle the identity and the contacts of
 *              the identity (Header file)
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

#ifndef __QBLDESKTOPADDRESSITENTITY_H__
#define __QBLDESKTOPADDRESSITENTITY_H__

#include <QFrame>
#include <QVBoxLayout>

#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-contact.h"

#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-list-address-row.h"

class QblDesktopAddressIdentity: public QWidget {
    Q_OBJECT

public:
    explicit QblDesktopAddressIdentity(QblJsonMainConfigIdentity *obj,
            QWidget *parent = 0);
    ~QblDesktopAddressIdentity();

    /**
     * Set item as active
     * @brief setActive
     * @param contact Contact which have to set active
     */
    void setActive(QblJsonMainConfigContact *contact);
    
    static bool compareAlias(QblDesktopAddressIdentity* first, QblDesktopAddressIdentity* second);
    
    std::string getAlias();
    
    const std::string& getPublicKey();
    
    void addContact(QblJsonMainConfigContact *contact);

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);

private:
    QblJsonMainConfigIdentity *obj;
    QFrame *frame;
    QVBoxLayout *layout;
    QblDesktopListIdentity *identity;
    std::list<QblDesktopListAddressRow *> items;
    std::list<QblJsonMainConfigContact *> contacts;
    int contactCount = 0;

    /**
     * Set height of the complete widget
     * @brief setHeight
     */
    void setHeight();
    
    /**
     * This function sorts the contact list by alias
     * @brief sortContactsByAlias
     */
    void sortContactsByAlias();
    
private slots:
    /**
     * Slot for identity collapsed button is pressed
     * @brief onListIdentityClicked
     * @param collapse
     */
    void onListIdentityClicked(bool collapse);
    /**
     * Slot for a address item is changed
     * @brief onListRowClicked
     */
    void onListRowChanged(QblJsonMainConfigContact *contact);
    /**
     * Slot for a address item is pressed
     * @brief onListRowClicked
     */
    void onListRowClicked(QblJsonMainConfigContact *contact);

signals:
    void collapsedClicked();
    void addressChanged(QblJsonMainConfigContact *contact);
    void addressClicked(QblJsonMainConfigIdentity *identity,
                        QblJsonMainConfigContact *contact);
};

#endif // __QBLDESKTOPADDRESSITENTITY_H__
