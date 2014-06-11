/**
 * @file       qbl-desktop-wizard-page-ffsyncserver.cpp
 * @brief      Class for the ff-sync server page of the first use wizard (Implementation)
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
#include "qbl-desktop-wizard-page-ffsyncserver.h"

QblDesktopWizardPage_FFSyncServer::QblDesktopWizardPage_FFSyncServer(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("Firefox sync server");
    this->setSubTitle("Choose the sync server you want to use");
    urlLabel = new QLabel("Server address:");
    urlLineEdit = new QLineEdit("http://sync.qabel.de");
    portLabel = new QLabel("Server Port:");
    portLineEdit = new QLineEdit("5000");
    authMailLabel = new QLabel("E-Mail: ");
    authMailLineEdit = new QLineEdit("f@f.de");
    authPasswdLabel = new QLabel("Password: ");
    authPasswdLineEdit = new QLineEdit("Test12345");

    authPasswdLineEdit->setEchoMode(QLineEdit::Password);
    authPasswdLineEdit->setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    authCodeLabel = new QLabel("Authentication Code:");
    authCodeLineEdit = new QLineEdit("12345678901234567890123456789012");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(urlLabel, 0, 0);
    layout->addWidget(urlLineEdit, 1, 0);
    layout->addWidget(portLabel, 0, 1);
    layout->addWidget(portLineEdit, 1, 1);
    layout->addWidget(authMailLabel, 2, 0);
    layout->addWidget(authMailLineEdit, 3, 0);
    layout->addWidget(authPasswdLabel, 2, 1);
    layout->addWidget(authPasswdLineEdit, 3, 1);
    layout->addWidget(authCodeLabel, 4, 0);
    layout->addWidget(authCodeLineEdit, 5, 0);
    this->registerField("ffsyncUrl", urlLineEdit);
    this->registerField("ffsyncPort", portLineEdit);
    this->registerField("ffsyncMail", authMailLineEdit);
    this->registerField("ffsyncPasswd", authPasswdLineEdit);
    this->registerField("ffsyncCode", authCodeLineEdit);
    setLayout(layout);
    return;
}

int QblDesktopWizardPage_FFSyncServer::nextId() const {
    return QblDesktopWizard::LastPage;
}
