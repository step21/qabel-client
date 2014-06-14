/**
 * @file		main.cpp
 * @brief		Main function of the Qabel client (Header file)
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

#include <QApplication>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <stdlib.h>
//include <QtMultimedia>
//#include <QSoundEffect>

#include "qbl-client.h"
#include "qbl-config-file.h" // only for getting path to sound logo
#include "qbl-desktop-client.h"
#include "desktop/qbl-desktop-wizard.h"

int main(int argc, char *argv[])
{
//    QSoundEffect soundLogo;
//    std::string soundFile;
//    soundFile.append(QblConfigFile::getCacheChatDir().substr(0, QblConfigFile::getCacheChatDir().size() - 4).append("QABEL_Sound_Logo_Final_44kHz_16Bit.wav"));
    
//    soundLogo.setSource(QUrl::fromLocalFile(QString::fromStdString(soundFile)));
//    soundLogo.setLoopCount(1);
//    soundLogo.setVolume(1.0f);
//    soundLogo.play();
    
    QApplication application(argc, argv);

    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(0, QObject::tr("Qable-Client"),
                QObject::tr("Handle this!!!"));
        return (EXIT_FAILURE);
    }

    QApplication::setQuitOnLastWindowClosed(false);
    QWidget *widget = NULL;
    
    Qbl *qbl = Qbl::getInstance();
    /* the lib makes no guarantee to return an instance */
    if (!qbl) {
        QMessageBox::critical(0, QObject::tr("Qabel-Client"),
                QObject::tr("Could not initialize the Qabel library"));
        return (EXIT_FAILURE);
    }
    
    if(qbl->getConfig()->isDefault()) {
        widget = new QblDesktopWizard(widget);
    }
    else {
        widget = new QblDesktopClient();
    }
    widget->show();
    
    // TODO switch for different versions

    return application.exec();
}
