/**
 * @file       qbl-desktop-wizard-page-intro.cpp
 * @brief      Class for the intro page of the first use wizard (Implementation)
 * @author     Fabian Träger <traeger@praemandatum.de>
 *
 * copyright:  (C) 2014 by Qabel GmbH
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

#include <QFormLayout>

#include "../qbl-desktop-wizard.h"
#include "qbl-desktop-wizard-page-intro.h"


QblDesktopWizardPage_Intro::QblDesktopWizardPage_Intro(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Welcome to Qabel");
    this->setSubTitle("Please choose how you want to configure your program!");
    this->rbtnNewUser = new QRadioButton("Create a new user identity");
    this->rbtnAddDevice = new QRadioButton("Add existing configuration to a new device");
    this->rbtnLogin = new QRadioButton("Login to an existing account");
    this->rbtnNewUser->setChecked(true);
    QFormLayout *layout = new QFormLayout;
    layout->insertRow(0, rbtnAddDevice);
    layout->insertRow(0, rbtnLogin);
    layout->insertRow(0, rbtnNewUser);
    this->registerField("rbtnLogin", rbtnLogin);
    this->registerField("rbtnNewUser", rbtnNewUser);
    setLayout(layout);
    return;
}

int QblDesktopWizardPage_Intro::nextId() const {
    if(this->rbtnNewUser->isChecked()) {
        return QblDesktopWizard::NewUser;
    }
    else if(this->rbtnLogin->isChecked()) {
        return QblDesktopWizard::FFSyncServer;
    }
    else {
        return QblDesktopWizard::AddDevice;
    }
}
