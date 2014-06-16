/**
 * @file		qbl-desktop-list-item.h
 * @brief		Default desktop list element (Header file)
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

#ifndef __QBL_DESKTOP_LIST_ITEM_H__
#define __QBL_DESKTOP_LIST_ITEM_H__

#include <json.h>

#include <QWidget>
#include <QMouseEvent>

#include "config/qbl-json-object.h"

/**
 * Class QblDesktopListItem: Default desktop list element
 * @brief The QblDesktopListItem class
 */
class QblDesktopListItem: public QWidget {
    //Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopListItem
     * @param parent
     */
    explicit QblDesktopListItem(QblJsonObject *obj, QWidget *parent = 0);
    ~QblDesktopListItem();

    QblJsonObject *getJsonObject();
    void setJsonObject(QblJsonObject *obj);
    /**
     * Set the text of the list item
     * @brief setText
     * @param text New text
     */
    virtual void setText(QString text) = 0;
    /**
     * Get the text of the list item
     * @brief text
     * @return Current text visible on item
     */
    virtual QString text() = 0;

public slots:

protected:
    QblJsonObject *obj;             /**< JSON object with information about the
                                      identity */

private:

private slots:

signals:

};

#endif // __QBL_DESKTOP_LIST_ITEM_H__
