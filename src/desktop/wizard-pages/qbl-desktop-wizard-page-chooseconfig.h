/**
 * @file       qbl-desktop-wizard-page-chooseconfig.h
 * @brief      Class for the choose config page of the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_PAGE_CHOOSECONFIG_H
#define QBLDESKTOPWIZARD_PAGE_CHOOSECONFIG_H

#include <QWizardPage>
#include <QRadioButton>

class QblDesktopWizardPage_ChooseConfig : public QWizardPage
{
    Q_OBJECT
public:
    QblDesktopWizardPage_ChooseConfig(QWidget *parent);
    int nextId() const;
private:
    QRadioButton *rbtnStandardConfig;
    QRadioButton *rbtnExpertConfig;
};


#endif // QBLDESKTOPWIZARD_PAGE_CHOOSECONFIG_H
