/**
 * @file       qbl-desktop-wizard-page-lastpage.cpp
 * @brief      Class for the last page of the first use wizard (Implementation)
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

#include <QGridLayout>

#include "../qbl-desktop-wizard.h"
#include "qbl-desktop-wizard-page-lastpage.h"

QblDesktopWizardPage_LastPage::QblDesktopWizardPage_LastPage(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Confirmation");
    
    return;
}

void QblDesktopWizardPage_LastPage::initializePage() {
    QVBoxLayout *layout = new QVBoxLayout();

    if(field("rbtnNewUser") == true) {
        userGroupBox = new QGroupBox("User");
        nickTitleLabel = new QLabel("Nickname:");
        nickLabel = new QLabel(field("nickname").toString());
        QGridLayout *userLayout = new QGridLayout();
        userLayout->addWidget(nickTitleLabel, 0, 0);
        userLayout->addWidget(nickLabel, 0, 1);
        userGroupBox->setLayout(userLayout);

        identityGroupBox = new QGroupBox("Identity");
        aliasTitleLabel = new QLabel("Alias:");
        aliasLabel = new QLabel(field("alias").toString());
        inboxTitleLabel = new QLabel("Inbox:");
        inboxLabel = new QLabel(field("inbox").toString());
        QGridLayout *identityLayout = new QGridLayout();
        identityLayout->addWidget(aliasTitleLabel, 0, 0);
        identityLayout->addWidget(aliasLabel, 0, 1);
        identityLayout->addWidget(inboxTitleLabel, 1, 0);
        identityLayout->addWidget(inboxLabel, 1, 1);
        identityGroupBox->setLayout(identityLayout);

        layout->addWidget(userGroupBox);
        layout->addWidget(identityGroupBox);
    }

    if(field("rbtnLogin") == true) {
        ffsyncGroupBox = new QGroupBox("Firefox Sync");
        urlTitleLabel = new QLabel("Server:");
        urlLabel = new QLabel(field("ffsyncUrl").toString());
        portTitleLabel = new QLabel("Port:");
        portLabel = new QLabel(field("ffsyncPort").toString());
        authMailTitleLabel = new QLabel("Mail");
        authMailLabel = new QLabel(field("ffsyncMail").toString());
        authCodeTitleLabel = new QLabel("Authentication Code");
        authCodeLabel = new QLabel(field("ffsyncCode").toString());
        QGridLayout *ffsyncLayout = new QGridLayout();
        ffsyncLayout->addWidget(urlTitleLabel, 0, 0);
        ffsyncLayout->addWidget(urlLabel, 0, 1);
        ffsyncLayout->addWidget(portTitleLabel, 1, 0);
        ffsyncLayout->addWidget(portLabel, 1, 1);
        ffsyncLayout->addWidget(authMailTitleLabel, 2, 0);
        ffsyncLayout->addWidget(authMailLabel, 2, 1);
        ffsyncLayout->addWidget(authCodeTitleLabel, 3, 0);
        ffsyncLayout->addWidget(authCodeLabel, 3, 1);
        ffsyncGroupBox->setLayout(ffsyncLayout);

        layout->addWidget(ffsyncGroupBox);
    }
    setLayout(layout);
}

int QblDesktopWizardPage_LastPage::nextId() const {
    
    return -1;
}
