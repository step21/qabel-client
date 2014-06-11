/**
 * @file		qbl-desktop-content.cpp
 * @brief		Address book for the desktop application (Implementation)
 * @author		Michael Ott <michael@king-coder.de>
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

#include <QResizeEvent>

#include "qbl-desktop-content.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-list-identity.h"

#include "qbl.h"
#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-identity-array.h"

QblDesktopContent::QblDesktopContent(QblContent::contentType type,
        QWidget *parent) :
    QblContent(type, parent), ui(new Ui::QblDesktopContent)/*create main content frame*/, headerHeight(60)
{
    ui->setupUi(this);

    this->client = QblClient::getInstance();
    this->ui->btListBottom->hide();
    //left content frame
    this->wdList = new QWidget(this->ui->saAddressList);
    //left main frame
    this->ui->frAddressList->setStyleSheet(
            this->client->getCss().getStyleSheet("list-identity"));
    this->ui->saAddressList->setWidgetResizable(false);
    return;
}

QblDesktopContent::~QblDesktopContent()
{
    return;
}

void QblDesktopContent::changed()//Virtual
{
    return;
}

void QblDesktopContent::setHeaderHeight(int height)
{
    this->headerHeight = height;

    return;
}

void QblDesktopContent::resizeEvent(QResizeEvent *event)
{
    int address_width, height, ignoredHeight, addressListHeight;

    ignoredHeight = this->ui->frAddressList->height() -
            this->ui->saAddressList->height();

    height = ((QWidget*)this->parent()->parent())->height() -
            this->headerHeight;
    
    addressListHeight = height - (this->ui->frListTopBox->height() + this->ui->frListBottomBox->height());
    
    address_width = event->size().width() - this->ui->saAddressList->width();

    // set top boxes
    this->ui->topBox->setGeometry(this->ui->topBox->x(),
                                  this->ui->topBox->y(),
                                     event->size().width(),
                                     this->ui->topBox->height());
    
    // set content
    this->ui->frAddressList->resize(this->ui->saAddressList->width(),
                                    addressListHeight);
    this->ui->saAddressList->resize(this->ui->saAddressList->width(),
                                    addressListHeight - ignoredHeight);
    
    this->ui->frContentField->resize(address_width, height);
    
    // set bottom boxes
    this->ui->frListBottomBox->setGeometry(this->ui->frListBottomBox->x(),
                                           this->ui->frAddressList->y() +
                                           this->ui->frAddressList->height(),
                                           this->ui->frListBottomBox->width(),
                                           this->ui->frListBottomBox->height());

    
    this->ui->bottomBox->setGeometry(this->ui->bottomBox->x(),
                                     this->ui->frContentField->height() -
                                     this->ui->bottomBox->height(),
                                     event->size().width(),
                                     this->ui->bottomBox->height());

    return;
}
