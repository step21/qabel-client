/**
 * @file		qbl-css.cpp
 * @brief		Handle the style sheet of the application (Implementation)
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

#include <QFile>

#include "qbl-css.h"

QblCss::QblCss(QblCss::os os)
{
    QFile *file = NULL;

    switch (os) {
    case LINUX_DESKTOP:
        // TODO to implement

//        break;
    case WINDOWS_DESKTOP:
        // TODO to implement

//        break;
    case MAC_DESKTOP:
        // TODO to implement

//        break;
    case DESKTOP:
        file = new QFile(":/css/desktop.css");
        osPrefix = "desktop-";

        break;
    case ANDROID:
        // TODO to implement

        break;
    case IPHONE:
        // TODO to implement

        break;
    case IPAD:
        // TODO to implement

        break;
    }

    if (file != NULL) {
        if (file->open(QFile::ReadOnly) == true) {
            this->styleSheet = QLatin1String(file->readAll());
            file->close();
        }
        delete(file);
    }

    return;
}

QString QblCss::getStyleSheet(QString styleSheetName)
{
    QString result, fileName;
    

    fileName = QString(":/css/%1%2.css").arg(this->getPrefix()).arg(styleSheetName);
    QFile file(fileName);
    if (file.open(QFile::ReadOnly) == true) {
        result = QLatin1String(file.readAll());

        file.close();
    }

    return (result);
}

QString QblCss::getStyleSheet()
{
    return (this->styleSheet);
}

QString QblCss::getPrefix()
{
    return (this->osPrefix);
}
