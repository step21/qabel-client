/**
 * @file		qbl-content.cpp
 * @brief		Main class for the content (Implementation)
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

#include <QMessageBox>
#include <QObject>

#include "qbl-desktop-client.h"
#include "qbl-client.h"

QblClient *client = NULL;

QblClient *QblClient::getInstance()
{
    return (client);
}

QblClient *QblClient::getInstance(QblCss::os os, Qbl *library)
{
    if (client == NULL) {
        client = new QblClient(os, library);
    }

    return (client);
}

QblCss QblClient::getCss()
{
    return (this->css);
}

Qbl *QblClient::getLibrary()
{
    return (this->library);
}

void QblClient::setContentChanged(QblContent::contentType contentType)
{
    this->contentChanged = true;
    this->contentType = contentType;

    return;
}

void QblClient::resetContentChanged()
{
    this->contentChanged = false;
}

bool QblClient::getContentChanged()
{
    if (this->contentChanged == true) {
        int retval;
        QString msg, what;

        QMessageBox dialog;
        dialog.setText(QObject::tr("Content changed"));
        dialog.setIcon(QMessageBox::Warning);

        switch (this->contentType) {
        case QblContent::NONE:
            what = "";
            break;
        case QblContent::ADDRESSBOOK:
            what = QObject::tr("addressbook");
            break;
        case QblContent::CHAT:
            what = QObject::tr("chat");
            break;
        case QblContent::FILE:
            what = QObject::tr("files");
            break;
        case QblContent::SETTINGS:
            what = QObject::tr("settings");
            break;
        }

        msg = QObject::tr("Do you want to recard the changes in %1").arg(what);
        dialog.setInformativeText(msg);
        dialog.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        dialog.setDefaultButton(QMessageBox::No);

        retval = dialog.exec();
        switch (retval) {
        case QMessageBox::Yes:
            this->contentChanged = false;
            return (false);
            break;
        case QMessageBox::No:
            return (true);
            break;
        default:
            break;
        }

    }

    return (false);
}

QblClient::QblClient(QblCss::os os, Qbl *library) :
        css(os), library(library), contentChanged(false),
        contentType(QblContent::NONE)
{

    return;
}
