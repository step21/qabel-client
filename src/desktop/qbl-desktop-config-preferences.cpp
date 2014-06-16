#include "config/qbl-config-file.h"
#include "qbl.h"

#include "qbl-desktop-config-preferences.h"
#include "ui_qbl-desktop-config-preferences.h"

#include <QString>


QblDesktopConfigPreferences::QblDesktopConfigPreferences(QWidget *parent) :
    QWidget(parent), ui(new Ui::QblDesktopConfigPreferences)
{
    ui->setupUi(this);

    this->preferences=Qbl::getInstance()->getConfig()->getPreferences();
    this->initContent();

    connect(this->ui->edit, SIGNAL(clicked()), this, SLOT(on_edit_clicked()));
    connect(this->ui->save, SIGNAL(clicked()), this, SLOT(on_save_clicked()));

    return;
}


QblDesktopConfigPreferences::~QblDesktopConfigPreferences()
{
    delete (this->ui);

    return;
}

void QblDesktopConfigPreferences::initContent()
{
    this->ui->save->setVisible(false);
    this->ui->cancel->setVisible(false);
    this->ui->default_poll_interval->setText(QString::number(this->preferences->getDefaultPollInterval()));
    this->ui->desktop_height->setText(QString::fromStdString(this->preferences->getDesktopHeight()));
    this->ui->desktop_width->setText(QString::fromStdString(this->preferences->getDesktopWidth()));
    this->ui->desktop_x->setText(QString::fromStdString(this->preferences->getDesktopX()));
    this->ui->desktop_y->setText(QString::fromStdString(this->preferences->getDesktopY()));
    this->ui->ffsync_auth->setText(QString::fromStdString(this->preferences->getFFsyncAuth()));
    this->ui->ffsync_url->setText(QString::fromStdString(this->preferences->getFFsyncUrl()));

    if(this->preferences->getStartMinimized()==true) {
        this->ui->start_minimize->setChecked(true);
    }
    else {
        this->ui->start_minimize->setChecked(false);
    }

    if(this->preferences->getUseWebSockets()==true) {
        this->ui->use_websockets->setChecked(true);
    }
    else {
        this->ui->use_websockets->setChecked(false);
    }

    return;
}

void QblDesktopConfigPreferences::on_edit_clicked()
{
    this->initEdits();

    return;
}

void QblDesktopConfigPreferences::initEdits()
{

    this->ui->save->setVisible(true);
    this->ui->cancel->setVisible(true);
    this->ui->default_poll_interval->setText(QString::number(this->preferences->getDefaultPollInterval()));
    this->ui->desktop_height->setText(QString::fromStdString(this->preferences->getDesktopHeight()));
    this->ui->desktop_width->setText(QString::fromStdString(this->preferences->getDesktopWidth()));
    this->ui->desktop_x->setText(QString::fromStdString(this->preferences->getDesktopX()));
    this->ui->desktop_y->setText(QString::fromStdString(this->preferences->getDesktopY()));
    this->ui->ffsync_auth->setText(QString::fromStdString(this->preferences->getFFsyncAuth()));
    this->ui->ffsync_url->setText(QString::fromStdString(this->preferences->getFFsyncUrl()));

    return;
}

void QblDesktopConfigPreferences::storeChanges()
{
    this->preferences->setDefaultPollInterval(this->ui->default_poll_interval->text().toInt());
    this->preferences->setDesktopHeight(this->ui->desktop_height->text().toStdString());
    this->preferences->setDesktopWidth(this->ui->desktop_width->text().toStdString());
    this->preferences->setDesktopX(this->ui->desktop_x->text().toStdString());
    this->preferences->setDesktopY(this->ui->desktop_y->text().toStdString());
    this->preferences->setFFsyncAuth(this->ui->ffsync_auth->text().toStdString());
    this->preferences->setFFsyncUrl(this->ui->ffsync_url->text().toStdString());

    if(this->ui->start_minimize->isChecked()==true) {
        this->preferences->setStartMinimized(true);
    }
    else {
        this->preferences->setStartMinimized(false);
    }

    if(this->ui->use_websockets->isChecked()==true) {
        this->preferences->setUseWebSockets(true);
    }
    else {
        this->preferences->setUseWebSockets(false);
    }

    Qbl::getInstance()->getConfig()->configIsChanged();

    return;
}


void QblDesktopConfigPreferences::on_save_clicked()
{
    this->storeChanges();
    this->initContent();

    return;
}

void QblDesktopConfigPreferences::on_cancel_clicked()
{
    this->initContent();

    return;
}

void QblDesktopConfigPreferences::resizeEvent(QResizeEvent *event)
{
    
}
