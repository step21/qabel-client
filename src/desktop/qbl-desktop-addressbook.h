/**
 * @file		qbl-desktop-addressbook.h
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

#ifndef __QBL_DESKTOP_ADDRESSBOOK_H__
#define __QBL_DESKTOP_ADDRESSBOOK_H__

#include <QFrame>
#include <QLayout>

#include "qbl-desktop-content-addressbook.h"
#include "qbl-desktop-addressbook-content.h"
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
class QblDesktopAddressbook;
}

/**
 * Class QblDesktopAddressbook: Address book for the desktop application
 * @brief The QblDesktopAddressbook class
 */
class QblDesktopAddressbook: public QblDesktopContentAddressbook {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopAddressbook
     * @param parent
     */
    explicit QblDesktopAddressbook(QWidget *parent = 0);
    ~QblDesktopAddressbook();

public slots:

protected:
    void resizeEvent(QResizeEvent *event);

private:
    QblDesktopAddressbookContent *content = NULL;
private slots:
    /**
     * Handle when a contact of the list is clicked
     * @todo check whether address is changed before override
     * @brief onContactClicked
     * @param contact
     */
    void onContactClicked(QblJsonMainConfigIdentity *identity,
                          QblJsonMainConfigContact *contact);

signals:

};

#endif // __QBL_DESKTOP_ADDRESSBOOK_H__
