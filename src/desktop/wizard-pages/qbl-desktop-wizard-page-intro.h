/**
 * @file       qbl-desktop-wizard-page-intro.h
 * @brief      Class for the intro page of the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_PAGE_INTRO_H
#define QBLDESKTOPWIZARD_PAGE_INTRO_H

#include <QWidget>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QFileDialog>

#include "qbl-main-config.h"

class QblDesktopWizardPage_Intro : public QWizardPage
{
    Q_OBJECT
public:
    QblDesktopWizardPage_Intro(QWidget *parent);
    int nextId() const;
private:
    QRadioButton *rbtnNewUser;
    QRadioButton *rbtnAddDevice;
    QRadioButton *rbtnLogin;
};


#endif // QBLDESKTOPWIZARD_PAGE_INTRO_H
