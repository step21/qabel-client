/**
 * @file       qbl-desktop-wizard-page-chooseconfig.cpp
 * @brief      Class for the choose config page of the first use wizard (Implementation)
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
#include "qbl-desktop-wizard-page-chooseconfig.h"

QblDesktopWizardPage_ChooseConfig::QblDesktopWizardPage_ChooseConfig(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Configuration options");
    this->setSubTitle("Choose the configuration option you want to use");
    rbtnStandardConfig = new QRadioButton("Standard configuration");
    rbtnExpertConfig = new QRadioButton("Expert configuration");
    rbtnStandardConfig->setChecked(true);
    QFormLayout *layout = new QFormLayout;
    layout->insertRow(0, rbtnExpertConfig);
    layout->insertRow(0, rbtnStandardConfig);
    setLayout(layout);
    this->registerField("expertconfig", rbtnExpertConfig);
}

int QblDesktopWizardPage_ChooseConfig::nextId() const {
    if(this->rbtnStandardConfig->isChecked()) {
        return QblDesktopWizard::CreateMasterKey;
    }
    else {
        return QblDesktopWizard::CreateMasterKey;
    }
}
