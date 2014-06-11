#include "qbl-desktop-list-file-row.h"
#include "ui_qbl-desktop-list-row-config.h"
#include <QDebug>

QblDesktopListFileRow::QblDesktopListFileRow(QblJsonMainConfigShare *obj,QWidget *parent) :
        QWidget(parent), ui(new Ui::QblDesktopListSettingsRow), obj(obj)
{
    this->ui->setupUi(this);
    this->client = QblClient::getInstance();

    this->setText(QString::fromStdString(this->obj->getBasedir()));

    this->setCss();

    return;
}

QblDesktopListFileRow::~QblDesktopListFileRow()
{
    delete (this->ui);
}

void QblDesktopListFileRow::setText(QString text)
{
    this->ui->lbRow->setText(text);

    return;
}

QString QblDesktopListFileRow::text()
{
    return (this->ui->lbRow->text());
}

void QblDesktopListFileRow::setActive(QblJsonMainConfigShare *upload)
{
    if (this->obj==upload) {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-active"));
        emit(clicked(upload));
    } else {
        this->setCss();
    }

    return;
}


void QblDesktopListFileRow::mouseReleaseEvent(QMouseEvent* /*event*/)
{
    emit(changed(this->obj));
    return;
}

void QblDesktopListFileRow::setCss()
{
    if ((id % 2) == 0) {
        this->setStyleSheet(this->client->getCss().getStyleSheet("list-settings-row"));
    } else {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-another-row"));
    }

    return;
}

