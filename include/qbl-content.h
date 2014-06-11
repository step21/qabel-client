/**
 * @file		qbl-content.h
 * @brief		Main class for the content (Header file)
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

#ifndef __QBL_CONTENT_H__
#define __QBL_CONTENT_H__

#include <QWidget>

class QblContent: public QWidget {
    Q_OBJECT
public:
    /**
     * Enum to handle the current visible widget in content area
     * @brief The contentType enum
     */
    enum contentType {
        NONE,                       /**< No content */
        ADDRESSBOOK,                /** Address book is shown in content */
        CHAT,                       /** Chat is shown in content */
        FILE,                       /** Files area is shown in content */
        SETTINGS,                   /** Settings is shown in content */
    };

    /**
     * Constructor
     * @brief QblContent
     * @param parent Parent Qt widget
     */
    explicit QblContent(QblContent::contentType type, QWidget *parent = 0);

    /**
     * Return the content type
     * @brief getType
     * @return Content type
     */
    QblContent::contentType getType();

    signals:

public slots:

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);

private:
    enum contentType type;          /**< Type of the content */
};

#endif // __QBL_CONTENT_H__
