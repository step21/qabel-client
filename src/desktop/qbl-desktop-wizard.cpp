/**
 * @file       qbl-desktop-wizard.cpp
 * @brief      Class for the first use wizard (Implementation)
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

#include "qbl-desktop-wizard.h"
#include "qbl-desktop-client.h"
#include "qbl-config-file.h"
#include "wizard-pages/qbl-desktop-wizard-page-intro.h"
#include "wizard-pages/qbl-desktop-wizard-page-newuser.h"
#include "wizard-pages/qbl-desktop-wizard-page-chooseconfig.h"
#include "wizard-pages/qbl-desktop-wizard-page-choosedirectory.h"
#include "wizard-pages/qbl-desktop-wizard-page-createidentity.h"
#include "wizard-pages/qbl-desktop-wizard-page-createmasterkey.h"
#include "wizard-pages/qbl-desktop-wizard-page-ffsyncserver.h"
#include "wizard-pages/qbl-desktop-wizard-page-lastpage.h"
#include <QFormLayout>
#include "ffsync/qbl-ffsync.h"

QblDesktopWizard::QblDesktopWizard(QWidget *widget, QWidget *parent) :
    QWizard(parent), widget(widget)
{
    this->setWindowTitle ("First Start");
    setPage(PageIntro, new QblDesktopWizardPage_Intro(this));
    setPage(NewUser, new QblDesktopWizardPage_NewUser(this));
    setPage(ChooseConfig, new QblDesktopWizardPage_ChooseConfig(this));
    setPage(ChooseDir, new QblDesktopWizardPage_ChooseDirectory(this));
    setPage(CreateMasterKey, new QblDesktopWizardPage_CreateMasterKey(this));
    setPage(CreateIdentity, new QblDesktopWizardPage_CreateIdentity(this));
    setPage(FFSyncServer, new QblDesktopWizardPage_FFSyncServer(this));
    setPage(LastPage, new QblDesktopWizardPage_LastPage(this));
    this->config = Qbl::getInstance()->getConfig();
    return;
}

QblDesktopWizard::~QblDesktopWizard()
{
    return;
}

void QblDesktopWizard::accept()
{   
    if(field("rbtnLogin") == true) {
        FFSync *user = new FFSync(field("ffsyncMail").toString().toStdString(),
                                  field("ffsyncPasswd").toString().toStdString(),
                                  field("ffsyncUrl").toString().toStdString(),
                                  field("ffsyncPort").toInt(),
                                  field("ffsyncCode").toString().toStdString());
        bool result = user->sync();
        this->close();
        if(result == true){
            this->widget = new QblDesktopClient();
        }
    }
    if(field("rbtnNewUser") == true) {
        this->config->addIdentity(field("alias").toString().toStdString(),
                                  field("privateKey").toString().toStdString(),
                                  field("publicKey").toString().toStdString(),
                                  field("inbox").toString().toStdString());
        this->config->configIsChanged();
        this->close();
        this->widget = new QblDesktopClient();
        this->widget->show();
    }
    return;
}
