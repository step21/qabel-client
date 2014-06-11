#include "qbl-desktop-topinfo-list.h"
#include "ui_qbl-desktop-topinfo-list.h"

QblDesktopTopInfoList::QblDesktopTopInfoList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QblDesktopTopInfoList)
{
    ui->setupUi(this);
    
}

QblDesktopTopInfoList::~QblDesktopTopInfoList()
{
    delete ui;
}

void QblDesktopTopInfoList::addToInfoList()
{
    this->ui->liTopInfo->addItem("test");

    return;
}
