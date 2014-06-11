/**
 * @file       qbl-desktop-wizard-page-newuser.h
 * @brief      Class for the new user page of the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_PAGE_NEWUSER_H
#define QBLDESKTOPWIZARD_PAGE_NEWUSER_H

#include <QWidget>
#include <QWizard>
#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QRadioButton>
#include <QFileDialog>

class QblDesktopWizardPage_NewUser : public QWizardPage
{
    Q_OBJECT
public:
    QblDesktopWizardPage_NewUser(QWidget *parent);
    int nextId() const;
private:
    QLabel *nickLabel;
    QLineEdit *nickLineEdit;
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *emailLabel;
    QLineEdit *emailLineEdit;
};


#endif // QBLDESKTOPWIZARD_PAGE_NEWUSER_H
