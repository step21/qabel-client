/**
 * @file		qbl-desktop-list-address-row.h
 * @brief		One address list element (Header file)
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

#ifndef __QBL_DESKTOP_LIST_ADDRESS_ROW_H__
#define __QBL_DESKTOP_LIST_ADDRESS_ROW_H__

#include <QWidget>

#include "qbl-json-main-config-contact.h"

#include "qbl-desktop-list-item.h"
#include "qbl-client.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for a list element
 */
class QblDesktopListRow;
}

/**
 * class QblDesktopListAddressRow: A list element
 * @brief The QblDesktopListAddressRow class
 */
class QblDesktopListAddressRow : public QblDesktopListItem
{
    Q_OBJECT

public:
    explicit QblDesktopListAddressRow(QblJsonMainConfigContact *contact,
            int id, QWidget *parent = 0);
    ~QblDesktopListAddressRow();

    /**
     * Set the text of the list item
     * @brief setText
     * @param text New text
     */
    void setText(QString text);
    /**
     * Get the text of the list item
     * @brief text
     * @return Current text visible on item
     */
    QString text();
    /**
     * Set item as active
     * @brief setActive
     * @param contact Contact which have to set active
     */
    void setActive(QblJsonMainConfigContact *contact);
    
    static bool compareAlias(QblDesktopListAddressRow* first, QblDesktopListAddressRow* second);
    
    std::string getAlias();
    
    bool isEqual(QblJsonMainConfigContact* contact);

protected:
    void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::QblDesktopListRow *ui;
    QblJsonMainConfigContact* contact;
    int id;
    QblClient *client;

    /**
     * Set the style sheet for this item
     * @brief setStyleSheet
     */
    void setCss();

signals:
    void changed(QblJsonMainConfigContact *contact);
    void clicked(QblJsonMainConfigContact *contact);

};

#endif // __QBL_DESKTOP_LIST_ADDRESS_ROW_H__
