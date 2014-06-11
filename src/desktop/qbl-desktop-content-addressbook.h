#ifndef QBLDESKTOPCONTENTADDRESSBOOK_H
#define QBLDESKTOPCONTENTADDRESSBOOK_H
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



#include <QFrame>
#include <QLayout>

#include "qbl-content.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-address-identity.h"
#include "qbl-client.h"
#include "qbl-desktop-content.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the address book
 */
class QblDesktopContentAddressbook;
}

/**
 * Class QblDesktopContent: Address book for the desktop application
 * @brief The QblDesktopContent class
 */
class QblDesktopContentAddressbook: public QblDesktopContent {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopContent
     * @param parent
     */
    explicit QblDesktopContentAddressbook(QWidget *parent = 0);
    ~QblDesktopContentAddressbook();

    /**
     * This function have to call when there are changes on the address book
     * @todo delete old content
     * @brief changed
     */
    void changed();
    
    void addContact(QblDesktopAddressIdentity *identity, QblJsonMainConfigContact *contact);


public slots:

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);
private:
    std::list<QblDesktopAddressIdentity*> identityList; /**< List of all
                                                        identity widgets */
    QblDesktopAddressIdentity *item;
    
    /**
     * This function sorts the identity list by alias
     * @brief sortIdentitiesByAlias
     */
    void sortIdentitiesByAlias();
    
    QWidget *oldWdList = NULL;                /**< old Widget for the contact list */
    

private slots:
    void onListIdentityClicked(int id, bool collapse);
    /**
     * Handle the resize from the list (collapsed ist pressed=
     * @brief listResized
     */
    void listResized();
    /**
     * Handle when an address of the list is changed
     * @todo check whether address is changed before override
     * @brief onAddressClicked
     * @param contact
     */
    void onAddressChanged(QblJsonMainConfigContact *contact);
    /**
     * Handle when an address of the list is clicked
     * @todo check whether address is changed before override
     * @brief onAddressClicked
     * @param contact
     */
    void onAddressClicked(QblJsonMainConfigIdentity *identity,
                          QblJsonMainConfigContact *contact);
    /**
     * Handle when "Add contact" button is clicked
     * @brief onAddContactClicket
     */
    void onAddContactClicked();
    

signals:

};



#endif // QBLDESKTOPCONTENTADDRESSBOOK_H
