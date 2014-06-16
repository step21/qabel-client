#include "qbl-desktop-config-drop_servers.h"
#include "config/qbl-config-file.h"
#include "qbl.h"

#include "ui_qbl-desktop-config-drop_servers.h"


QblDesktopConfigDropServers::QblDesktopConfigDropServers(QWidget *parent) :
    QWidget(parent), ui(new Ui::QblDesktopConfigDropServers)
{

    this->dropservers=Qbl::getInstance()->getConfig()->getDropServers();
    this->initContent();

    connect(this->ui->edit, SIGNAL(clicked()), this, SLOT(on_edit_clicked()));
    connect(this->ui->save, SIGNAL(clicked()), this, SLOT(on_save_clicked()));

    return;
}

QblDesktopConfigDropServers::~QblDesktopConfigDropServers()
{
    delete (this->ui);

    return;
}

void QblDesktopConfigDropServers::initContent()
{
    this->ui->save->setVisible(false);
    this->ui->cancel->setVisible(false);

    return;
}

void QblDesktopConfigDropServers::on_edit_clicked()
{
    this->initEdits();

    return;
}

void QblDesktopConfigDropServers::initEdits()
{

    this->ui->save->setVisible(true);
    this->ui->cancel->setVisible(true);

    return;
}

void QblDesktopConfigDropServers::storeChanges()
{
    Qbl::getInstance()->getConfig()->configIsChanged();

    return;
}


void QblDesktopConfigDropServers::on_save_clicked()
{
    this->storeChanges();
    this->initContent();

    return;
}

void QblDesktopConfigDropServers::on_cancel_clicked()
{
    this->initContent();

    return;
}
