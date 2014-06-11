/**
 * @file       qbl-desktop-wizard-page-choosedirectory.h
 * @brief      Class for the choose directory page of the first use wizard (Header file)
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

#ifndef QBLDESKTOPWIZARD_PAGE_CHOOSEDIRECTORY_H
#define QBLDESKTOPWIZARD_PAGE_CHOOSEDIRECTORY_H

#include <QWizard>
#include <QWizardPage>
#include <QFileDialog>
#include <QLabel>
#include <QLineEdit>

class QblDesktopWizardPage_ChooseDirectory : public QWizardPage
{
    Q_OBJECT
public:
    QblDesktopWizardPage_ChooseDirectory(QWidget *parent);
    int nextId() const;
private slots:
    void on_pbSelectDir_clicked();    
    
private:
    QPushButton *pbSelectDir;
    QFileDialog *fileDialog;
    QLabel *lDirectory;
    QLineEdit *leDirectory;
};



#endif // QBLDESKTOPWIZARD_PAGE_CHOOSEDIRECTORY_H
