/**
 * @file		qbl-desktop-content-settings.cpp
 * @brief		Address book for the desktop application (Implementation)
 * @author		Alexander Hartmann <hartmannaf@googlemail.com>, Michael Ott <michael@king-coder.de>
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

#include <QResizeEvent>

#include "qbl-desktop-content-settings.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-settings-identity.h"

#include "qbl.h"
#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-identity-array.h"

#include "qbl-desktop-settings-constants.h"
#include "qbl-desktop-content.h"
#include "qdebug.h"

#include "qbl-desktop-config-preferences.h"


QblDesktopContentSettings::QblDesktopContentSettings(QWidget *parent) :
    QblDesktopContent(QblDesktopContent::SETTINGS, parent)
{
    this->changed();
}

QblDesktopContentSettings::~QblDesktopContentSettings()
{
    delete item;
    return;
}

void QblDesktopContentSettings::changed()
{
    // Creates main the Categorys for Settings
    item = new QblDesktopSettingsIdentity(MAINSETTINGS,this->wdList);
    this->mainSettingsCatagories.push_back(item);
    item = new QblDesktopSettingsIdentity(DROPSERVER,this->wdList);
    this->mainSettingsCatagories.push_back(item);
    item = new QblDesktopSettingsIdentity(IDENTITYS,this->wdList);
    this->mainSettingsCatagories.push_back(item);
    item = new QblDesktopSettingsIdentity(BLOCKSERVERS,this->wdList);
    this->mainSettingsCatagories.push_back(item);


    //adds the Signals to every item
    foreach(item,this->mainSettingsCatagories )
    {
        connect(item, SIGNAL(collapsedClicked()), this, SLOT(listResized()));
        connect(item, SIGNAL(settingChanged(int,int)),
                this, SLOT(onSettingChanged(int,int)));
        connect(item,SIGNAL(settingClicked(int,int)),this,
                SLOT(onSettingClicked(int,int)));
    }

    this->listResized();

    return;
}



void QblDesktopContentSettings::resizeEvent(QResizeEvent *event)
{
    QblDesktopContent::resizeEvent(event);
    

    return;
}

void QblDesktopContentSettings::onListIdentityClicked(int id, bool collapse)
{
    return;
}

void QblDesktopContentSettings::listResized()
{
    std::list<QblDesktopSettingsIdentity*>::iterator iterator;
    int height = 0;
    int x = 0;

    for (iterator = this->mainSettingsCatagories.begin();
         iterator != this->mainSettingsCatagories.end(); iterator++) {
        (*iterator)->setGeometry(0, x, (*iterator)->width(), (*iterator)->height());
        height += (*iterator)->height();
        x += (*iterator)->height();
    }

    this->wdList->setMaximumSize(this->ui->frAddressList->width(), height);
    this->wdList->setMinimumSize(this->ui->frAddressList->width(), height);
    this->ui->saAddressList->setWidget(this->wdList);


    return;
}

void QblDesktopContentSettings::onSettingChanged(int category, int id)
{
    if (this->client->getContentChanged() == false) {
        foreach(QblDesktopSettingsIdentity* item,mainSettingsCatagories)
        {
            item->setActive(id,category);
        }
    }

    return;
}

void QblDesktopContentSettings::onSettingClicked(int category,int id)
{
    if(category==MAINSETTINGS&&id==1) {
        emit(preferencesClicked());
    }
    if(category==DROPSERVER&&id==-1){
        emit(dropServersClicked());
    }
}


