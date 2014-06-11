/**
 * @file       qbl-desktop-wizard-page-newuser.cpp
 * @brief      Class for the new user page of the first use wizard (Implementation)
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
#include "qbl-desktop-wizard-page-newuser.h"

QblDesktopWizardPage_NewUser::QblDesktopWizardPage_NewUser(QWidget *parent)
    : QWizardPage(parent){
    this->setTitle("New user");
    this->setSubTitle("Enter your data");
    nickLabel = new QLabel("Nickname:");
    nickLineEdit = new QLineEdit();
    nameLabel = new QLabel("Name:");
    nameLineEdit = new QLineEdit();
    emailLabel = new QLabel("Email:");
    emailLineEdit = new QLineEdit();
    QFormLayout *layout = new QFormLayout;
    layout->addWidget(nickLabel);
    layout->addWidget(nickLineEdit);
    layout->addWidget(nameLabel);
    layout->addWidget(nameLineEdit);
    layout->addWidget(emailLabel);
    layout->addWidget(emailLineEdit);
    this->registerField("nickname", nickLineEdit);
    this->registerField("name", nameLineEdit);
    this->registerField("email", nameLineEdit);
    setLayout(layout);
    return;
}

int QblDesktopWizardPage_NewUser::nextId() const {
    return QblDesktopWizard::ChooseConfig;
}
