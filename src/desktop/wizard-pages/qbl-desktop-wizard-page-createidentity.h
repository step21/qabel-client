/**
 * @file       qbl-desktop-wizard-page-createidentity.h
 * @brief      Class for the create identity page of the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_PAGE_CREATEIDENTITY_H
#define QBLDESKTOPWIZARD_PAGE_CREATEIDENTITY_H

#include <QWizard>
#include <QWizardPage>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class QblDesktopWizardPage_CreateIdentity : public QWizardPage
{
    Q_OBJECT
public:
    QblDesktopWizardPage_CreateIdentity(QWidget *parent);
    int nextId() const;  
    QPushButton *generateKeyPairPushButton;
private slots:
    void generateKeyPairPushButtonClicked();
private:
    QLabel *aliasLabel;
    QLineEdit *aliasLineEdit;
    QLabel *privateKeyLabel;
    QLineEdit *privateKeyLineEdit;
    QLabel *publicKeyLabel;
    QLineEdit *publicKeyLineEdit;
    QLabel *inboxLabel;
    QLineEdit *inboxLineEdit;
    void dummyGenerateKeyPair(std::string &privateKey, std::string &publicKey);
};



#endif // QBLDESKTOPWIZARD_PAGE_CREATEIDENTITY_H
