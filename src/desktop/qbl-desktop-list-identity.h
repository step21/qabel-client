/**
 * @file		qbl-desktop-list-identity.h
 * @brief		List element for the identity (Header file)
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

#ifndef __QBL_DESKTOP_LIST_IDENTITY_H__
#define __QBL_DESKTOP_LIST_IDENTITY_H__

#include <json.h>

#include <QResizeEvent>

#include "qbl-desktop-list-item.h"
#include "config/qbl-json-main-config-identity.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the identity list element
 */
class QblDesktopListIdentity;
}

/**
 * Class QblDesktopListIdentity: List element for the identity
 * @brief The QblDesktopListIdentity class
 */
class QblDesktopListIdentity: public QblDesktopListItem {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopListIdentity
     * @param parent
     */
    explicit QblDesktopListIdentity(QblJsonMainConfigIdentity *identity,
            bool collapse = true, QWidget *parent = 0);
    ~QblDesktopListIdentity();

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
     * Get the collapse state of the identity entry
     * @brief getCollapse
     * @return true == collapse
     */
    bool getCollapse();
    /**
     * Set the collapse state of the identity entry
     * @brief setCollapse
     * @param collapse New collapse state
     */
    void setCollapse(bool collapse);

public slots:

protected:

private:
    Ui::QblDesktopListIdentity *ui; /**< Object handle the UI stuff */

    bool collapse;

private slots:
    void on_btCollapse_clicked();

signals:
    void collapsed(bool collapse);

};

#endif // __QBL_DESKTOP_LIST_IDENTITY_H__
