#include "qbl-desktop-fcontent.h"
#include "ui_qbl-desktop-fcontent.h"
#include <QString>
#include <QList>
#include <QStringList>
#include "qbl.h"
#include <QStandardItem>
#include <QResizeEvent>
#include <QDebug>
#include <QFileSystemModel>
#include <QMenu>
#include <QStringListModel>


QblDesktopFContent::QblDesktopFContent(QblContent::contentType type, QblJsonMainConfigShare *share,
        QWidget *parent) :
        QblContent(type,parent), ui(new Ui::QblDesktopFContent)
{
    ui->setupUi(this);
    this->share= share;
    this->root = QString::fromStdString(share->getBasedir());

    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);

    this->filesys = new QFileSystemModel(this);
    this->filesys->setReadOnly(false);
    this->filesys->setFilter(QDir::NoDot | QDir::AllEntries | QDir::System);

    this->showDirectory();


    ui->tableView->setMaximumHeight(this->ui->FileFrame->height()-this->ui->FileBottomFrame->height()-this->ui->FileTopFrame->height());
    ui->tableView->setMinimumHeight(this->ui->FileFrame->height()-this->ui->FileBottomFrame->height()-this->ui->FileTopFrame->height());
    ui->tableView->setMinimumWidth(this->ui->FileFrame->width());
    ui->tableView->setMaximumWidth(this->ui->FileFrame->width());

    connect(ui->tableView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(contextMenu(QPoint)));

}

QblDesktopFContent::~QblDesktopFContent()
{
    delete ui;
    return;
}

void QblDesktopFContent::resizeEvent(QResizeEvent *event)
{
    ui->tableView->setMaximumHeight(this->ui->FileFrame->height()-this->ui->FileBottomFrame->height()-this->ui->FileTopFrame->height());
    ui->tableView->setMinimumHeight(this->ui->FileFrame->height()-this->ui->FileBottomFrame->height()-this->ui->FileTopFrame->height());
    ui->tableView->setMinimumWidth(this->ui->FileFrame->width());
    ui->tableView->setMaximumWidth(this->ui->FileFrame->width());

}


void QblDesktopFContent::showDirectory() {

    std::list<int> *contactList;
    std::list<int>::iterator ListIterator;
    QStringListModel *model = new QStringListModel(this);
    this->ui->tableView->setModel(this->filesys);
    ui->tableView->setRootIndex(this->filesys->setRootPath(this->root));
    this->ui->path->setText(this->root);

    contactList=this->share->getContacts();

    for (ListIterator = contactList->begin(); ListIterator != contactList->end();ListIterator++) {
       QString contact=QString::number(*(ListIterator));
        model->insertRow(model->rowCount());
        QModelIndex index = model->index(model->rowCount()-1);
        model->setData(index, contact);
    }
    this->ui->listView->setModel(model);
}


//Open Directory

void QblDesktopFContent::on_tableView_doubleClicked(const QModelIndex &index)
{
    QFileInfo fileInfo(this->filesys->filePath(index));
    if(fileInfo.isDir()){
            moveTo(fileInfo.absoluteFilePath());
    }

}

void QblDesktopFContent::moveTo(const QString& path)
{
    ui->path->setText(path);
    QModelIndex index(this->filesys->index(path));
    ui->tableView->setRootIndex(index);

}


void QblDesktopFContent::on_pushButton_clicked() {

}

void QblDesktopFContent::contextMenu(const QPoint &pos){
    QMenu menu(this);
    QModelIndex cell = ui->tableView->indexAt(pos);

    if(cell.isValid()){
        QModelIndex id;
        id=cell.sibling(cell.row(),0);
        menu.addAction("Delete",this,SLOT(deleteItem()));
        menu.addAction("Share",this,SLOT(deleteItem()));
        menu.exec(ui->tableView->mapToGlobal(pos));
    }
}

void QblDesktopFContent::deleteItem(){

}


