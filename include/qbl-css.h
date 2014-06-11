/**
 * @file		qbl-css.h
 * @brief		Handle the style sheet of the application (Header file)
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

#ifndef __QBLCSS_H__
#define __QBLCSS_H__

#include <QString>

/**
 * Class QblCss: handle the style sheet of the application (Header file)
 * @brief The QblCss class
 */
class QblCss {
public:
    /**
     * @brief The os enum
     */
    enum os {
        DESKTOP,                    /**< Application run on a desktop */
        LINUX_DESKTOP,              /**< Application run on a linux desktop */
        WINDOWS_DESKTOP,            /**< Application run on a windows
                                      desktop */
        MAC_DESKTOP,                /**< Application run on a mac desktop */
        ANDROID,                    /**< Application run on a android base
                                      system */
        IPHONE,                     /**< Application run on a iPhone */
        IPAD,                       /**< Application run on a iPad */
    };

    /**
     * Constructor
     * @todo not complete implemented
     * @brief QblCss
     * @param os "Operation system" to use
     */
    QblCss(QblCss::os os);

    /**
     * Get style sheet as string
     * @brief getStyleSheet
     * @param styleSheetName Name of the style sheet
     * @return Style sheet or empty string when error
     */
    QString getStyleSheet(QString styleSheetName);
    /**
     * Get style sheet as string
     * @brief getStyleSheet
     * @return Style sheet or empty string when error
     */
    QString getStyleSheet();
    /**
     * Get prefix for the style sheets
     * @brief getPrefix
     * @return
     */
    QString getPrefix();

private:
    QString styleSheet;             /**< Style sheet */
    QString osPrefix;               /**< Prefix for the stylesheet */
};

#endif // __QBLCSS_H__
