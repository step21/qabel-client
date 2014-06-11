/**
 * @file       qbl-desktop-wizard-page-createmasterkey.cpp
 * @brief      Class for the create master key page of the first use wizard (Implementation)
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

#include <QVBoxLayout>

#include "../qbl-desktop-wizard.h"
#include "qbl-desktop-wizard-page-createmasterkey.h"

QblDesktopWizardPage_CreateMasterKey::QblDesktopWizardPage_CreateMasterKey(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Master key");
    this->setSubTitle("In order to secure your data you have to generate a master key");
    promptLabel = new QLabel();
    keyTextBrowser = new QTextBrowser;
    generateKeyPushButton = new QPushButton("Generate Key");
    
    connect(generateKeyPushButton, SIGNAL(clicked()), this, SLOT(generateKeyPushButtonClicked()));
    
    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(promptLabel);
    layout->addWidget(keyTextBrowser);
    layout->addWidget(generateKeyPushButton);
    setLayout(layout);
    this->registerField("masterKey", keyTextBrowser);
    return;
}

int QblDesktopWizardPage_CreateMasterKey::nextId() const {
    return QblDesktopWizard::CreateIdentity;
}

void QblDesktopWizardPage_CreateMasterKey::generateKeyPushButtonClicked() {
    promptLabel->setText("Please print or note this key!");
    keyTextBrowser->setText(QString::fromStdString(this->dummyGenerateKey()));
    return;
}

std::string QblDesktopWizardPage_CreateMasterKey::dummyGenerateKey() {
    return std::string("!xc&kip235 (to be done, just an example key)");
}
