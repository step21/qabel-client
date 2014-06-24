/**
 * @file		qbl-desktop-addressbook-content.cpp
 * @brief		Addressbook windows for the desktop application (Implementation)
 * @author		Fabian Träger <traeger@praemandatum.de>
 *
 * copyright:	(C) 2014 by Qabel GmbH
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

#include "config/qbl-config-file.h"
#include "qbl.h"

#include "qbl-desktop-addressbook-content.h"
#include "ui_qbl-desktop-addressbook-content.h"

QblDesktopAddressbookContent::QblDesktopAddressbookContent(
        QblJsonMainConfigIdentity *identity,
        QblJsonMainConfigContact *contact,
        QWidget *parent) :
    QWidget(parent), ui(new Ui::QblDesktopAddressbookContent),
    identity(identity), contact(contact)
{
    ui->setupUi(this);
    this->initContent();
    
    connect(this->ui->btEditContact, SIGNAL(clicked()), this, SLOT(on_btEditContact_clicked()));
    connect(this->ui->btStoreChanges, SIGNAL(clicked()), this, SLOT(on_btStoreChanges_clicked()));
    return;
}

QblDesktopAddressbookContent::~QblDesktopAddressbookContent()
{
    delete (this->ui);
    
    return;
}

void QblDesktopAddressbookContent::initContent()
{
    this->ui->btStoreChanges->setVisible(false);
    this->ui->btCancel->setVisible(false);
    this->ui->stackedWidgetContactData->setCurrentIndex(0);
    this->ui->stackedWidgetContactNotes->setCurrentIndex(0);
    this->ui->lbMyID->setText(QString::fromStdString(this->identity->getAlias()));
    this->ui->lbAliasContent->setText(QString::fromStdString(this->contact->getAlias()));
    this->ui->lbForenameContent->setText(QString::fromStdString(this->contact->getForename()));
    this->ui->lbSurnameContent->setText(QString::fromStdString(this->contact->getSurname()));
    this->ui->lbMailContent->setText(QString::fromStdString(this->contact->getMailAddress()));
    this->ui->lbPhoneContent->setText(QString::fromStdString(this->contact->getPhoneNumber()));
    this->ui->lbNotesContent->setText(QString::fromStdString(this->contact->getNotes()));
    
    return;
}

void QblDesktopAddressbookContent::on_btEditContact_clicked()
{
    this->initEdits();
    
    return;
}

void QblDesktopAddressbookContent::resizeEvent(QResizeEvent *event)
{   
    
    // set top content
    this->ui->frContentTopBox->resize(event->size().width(),
                                      this->ui->frContentTopBox->height());
    
    // set scroll area
    this->ui->saContact->resize(event->size().width(),
                                event->size().height() -
                                this->ui->frContentTopBox->height() -
                                this->ui->frContentBottomBox->height());
    
    // set bottom content
    this->ui->frContentBottomBox->setGeometry(0,
                                              event->size().height() -
                                              this->ui->frContentBottomBox->height(),
                                              event->size().width(),
                                              this->ui->frContentBottomBox->height());    
}

void QblDesktopAddressbookContent::initEdits() 
{
    
    this->ui->leForename->setText(QString::fromStdString(this->contact->getForename()));
    this->ui->leSurname->setText(QString::fromStdString(this->contact->getSurname()));
    this->ui->leMail->setText(QString::fromStdString(this->contact->getMailAddress()));
    this->ui->lePhone->setText(QString::fromStdString(this->contact->getPhoneNumber()));
    this->ui->teNotes->setText(QString::fromStdString(this->contact->getNotes()));
    this->ui->stackedWidgetContactData->setCurrentIndex(1);
    this->ui->stackedWidgetContactNotes->setCurrentIndex(1);
    this->ui->btStoreChanges->setVisible(true);
    this->ui->btCancel->setVisible(true);
    
    return;
}

void QblDesktopAddressbookContent::storeChanges()
{
    this->contact->setForename(this->ui->leForename->text().toStdString());
    this->contact->setSurname(this->ui->leSurname->text().toStdString());
    this->contact->setMailAddress(this->ui->leMail->text().toStdString());
    this->contact->setPhoneNumber(this->ui->lePhone->text().toStdString());
    this->contact->setNotes((this->ui->teNotes->toPlainText().toStdString()));
    Qbl::getInstance()->getConfig()->configIsChanged();
    
    return;
}


void QblDesktopAddressbookContent::on_btStoreChanges_clicked()
{
    this->storeChanges();
    this->initContent();
    
    return;
}

void QblDesktopAddressbookContent::on_btCancel_clicked()
{
    this->initContent();
    
    return;
}

void QblDesktopAddressbookContent::on_btRemove_clicked()
{
    return;
}
