
#include "qbl-desktop-list-settings-row.h"
#include "ui_qbl-desktop-list-row-config.h"

QblDesktopListSettingsRow::QblDesktopListSettingsRow(std::string category_name,
        int id,int category, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::QblDesktopListSettingsRow), id(id),category(category)
{
    this->ui->setupUi(this);
    this->client = QblClient::getInstance();

    this->setText(QString::fromStdString(category_name));

    this->setCss();

    return;
}

QblDesktopListSettingsRow::~QblDesktopListSettingsRow()
{
    delete (this->ui);
}

void QblDesktopListSettingsRow::setText(QString text)
{
    this->ui->lbRow->setText(text);

    return;
}

QString QblDesktopListSettingsRow::text()
{
    return (this->ui->lbRow->text());
}

void QblDesktopListSettingsRow::setActive(int id,int category)
{
    if (this->id==id&&this->category==category) {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-active"));
        emit(clicked(this->category,this->id));
    } else {
        this->setCss();
    }

    return;
}


void QblDesktopListSettingsRow::mouseReleaseEvent(QMouseEvent* /*event*/)
{
    emit(changed(this->category,this->id));

    return;
}

void QblDesktopListSettingsRow::setCss()
{
    if ((id % 2) == 0) {
        this->setStyleSheet(this->client->getCss().getStyleSheet("list-settings-row"));
    } else {
        this->setStyleSheet(
                    this->client->getCss().getStyleSheet("list-another-row"));
    }

    return;
}

