/**
 * @file       qbl-desktop-wizard-page-createidentity.cpp
 * @brief      Class for the create identity page of the first use wizard (Implementation)
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
#include <QGroupBox>
#include <QVBoxLayout>

#include "../qbl-desktop-wizard.h"
#include "qbl-desktop-wizard-page-createidentity.h"

QblDesktopWizardPage_CreateIdentity::QblDesktopWizardPage_CreateIdentity(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Identity");
    this->setSubTitle("Create a new identity");
    aliasLabel = new QLabel("Alias:");
    aliasLineEdit = new QLineEdit();
    inboxLabel = new QLabel("Inbox:");
    inboxLineEdit = new QLineEdit();
    privateKeyLabel = new QLabel("Private key:");
    privateKeyLineEdit = new QLineEdit();
    publicKeyLabel = new QLabel("Public key:");
    publicKeyLineEdit = new QLineEdit();
    generateKeyPairPushButton = new QPushButton("Generate key pair");
    connect (generateKeyPairPushButton, SIGNAL(clicked()), this, SLOT(generateKeyPairPushButtonClicked()));
    QFormLayout *layout = new QFormLayout();
    QGroupBox *groupBox = new QGroupBox("Key pair");
    QVBoxLayout *groupBoxLayout = new QVBoxLayout();
    groupBoxLayout->addWidget(privateKeyLabel);
    groupBoxLayout->addWidget(privateKeyLineEdit);
    groupBoxLayout->addWidget(publicKeyLabel);
    groupBoxLayout->addWidget(publicKeyLineEdit);
    groupBoxLayout->addWidget(generateKeyPairPushButton);
    groupBox->setLayout(groupBoxLayout);
    layout->addWidget(aliasLabel);
    layout->addWidget(aliasLineEdit);
    layout->addWidget(inboxLabel);
    layout->addWidget(inboxLineEdit);
    layout->addWidget(groupBox);
    setLayout(layout);
    this->registerField("alias", aliasLineEdit);
    this->registerField("privateKey", privateKeyLineEdit);
    this->registerField("publicKey", publicKeyLineEdit);
    this->registerField("inbox", inboxLineEdit);
    return;
}

int QblDesktopWizardPage_CreateIdentity::nextId() const {
    if(field("expertconfig").toBool()) {
        return QblDesktopWizard::FFSyncServer;
    }
    else {
        return QblDesktopWizard::LastPage;
    }
}

void QblDesktopWizardPage_CreateIdentity::generateKeyPairPushButtonClicked() {
     std::string privateKey;
    std::string publicKey;   
    dummyGenerateKeyPair(privateKey, publicKey);
    privateKeyLineEdit->setText(QString::fromStdString(privateKey));
    publicKeyLineEdit->setText(QString::fromStdString(publicKey));
}

void QblDesktopWizardPage_CreateIdentity::dummyGenerateKeyPair(std::string &privateKey, std::string &publicKey) {
    privateKey = "to be done, just dummy field for private key";
    publicKey = "to be done, just dummy field for public key";    
}
