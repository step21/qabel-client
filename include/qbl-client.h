/**
 * @file		qbl-client.h
 * @brief		Main class with some default values
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

#ifndef __QBLCLIENT_H__
#define __QBLCLIENT_H__

#include <qbl.h>

#include "qbl-css.h"
#include "qbl-content.h"

/**
 * Class Qbl: Main class with some default values
 * @brief The QblClient class
 */
class QblClient {
public:
    /**
     * Get a singleton of the main class
     * @brief getInstance
     * @return Singleton object or NULL when OS is not set
     */
    static QblClient *getInstance();
    /**
     * Get a singleton of the main class
     * @brief getInstance
     * @param os "Operation system" on which application shall run
     * @return Singleton object
     */
    static QblClient *getInstance(QblCss::os os, Qbl *library);
    /**
     * Get the object of the style sheet class
     * @brief getCss
     * @return Object of QblCss
     */
    QblCss getCss();
    /**
     * Get the object of the library
     * @brief getLibrary
     * @return Object of the library
     */
    Qbl *getLibrary();
    /**
     * Set here when the content in any area is changed
     * @todo not complete tested
     * @brief setContentChanged
     * @param contentType Type of content which is changed
     */
    void setContentChanged(QblContent::contentType contentType);
    /**
     * Set here when the changes in content are saved
     * @todo not complete tested
     * @brief setContentChanged
     * @param contentType Type of content which is changed
     */
    void resetContentChanged();
    /**
     * When the content in any area is changed and the user do not want to
     * ignore changes the function return true otherwise false
     * @brief getContentChanged
     * @return true when changes will not igored
     */
    bool getContentChanged();

protected:

private:
    QblCss css;                     /**< Style sheet object */
    Qbl *library;                   /**< Library object */
    bool contentChanged;            /**< Is content changed */
    QblContent::contentType contentType; /**< and what is changed */

    /**
     * Constructor
     * @brief QblClient
     * @param os "Operation system" on which application shall run
     */
    QblClient(QblCss::os os, Qbl *library);

};

#endif // __QBLCLIENT_H__
