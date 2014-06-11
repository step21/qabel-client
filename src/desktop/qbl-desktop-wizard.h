/**
 * @file       qbl-desktop-wizard.h
 * @brief      Class for the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_H
#define QBLDESKTOPWIZARD_H

#include <QWidget>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QFileDialog>

#include "qbl.h"
#include "qbl-main-config.h"
#include "qbl-desktop-content.h"
#include "qbl-content.h"
#include "qbl-desktop-client.h"

class QblDesktopWizard : public QWizard
{
    Q_OBJECT
    
public:
    explicit QblDesktopWizard(QWidget *widget, QWidget *parent = 0);
    ~QblDesktopWizard();
    
    enum {
        PageIntro,
        NewUser,
        AddDevice,
        Login,
        CreateIdentity,
        ChooseConfig,
        ChooseDir,
        CreateMasterKey,
        FFSyncServer,
        LastPage
    };
    
    void accept();
    
private:
    QblMainConfig *config;
    QWidget *widget;
};



#endif // QBLDESKTOPWIZARD_H
