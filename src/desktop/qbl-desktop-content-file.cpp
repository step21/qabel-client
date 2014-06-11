#include "qbl-desktop-content-file.h"
#include "ui_qbl-desktop-content.h"
#include "qbl.h"
#include "qbl-desktop-list-file-row.h"


QblDesktopContentFile::QblDesktopContentFile(QWidget *parent) :
    QblDesktopContent(QblDesktopContent::FILE, parent)
{
    this->changed();
}


QblDesktopContentFile::~QblDesktopContentFile()
{

    delete item;
    return;
}

void QblDesktopContentFile::changed()
{
    Qbl *qbl;
    std::list<QblJsonMainConfigShare *> list;
    std::list<QblJsonMainConfigShare *>::iterator iterator;


    /** TODO delete old content */
    /* create upload list */

    qbl = Qbl::getInstance();
    if (qbl == NULL) {
        exit(0);
    }

    list = qbl->getConfig()->getShares()->getList();
    for (iterator = list.begin(); iterator != list.end(); iterator++) {
        item = new QblDesktopListFileRow(*iterator, this->wdList);
        connect(item, SIGNAL(changed(QblJsonMainConfigShare*)),
                this, SLOT(onFileChanged(QblJsonMainConfigShare*)));
        connect(item,SIGNAL(clicked(QblJsonMainConfigShare*)),
                 this,SLOT(onFileClicked(QblJsonMainConfigShare*)));
        this->identityList.push_back(item);
    }

    this->listResized();

    return;
}


void QblDesktopContentFile::resizeEvent(QResizeEvent *event)
{
    /*Addressbook*/
    int address_width, height, ignoredHeight;

    ignoredHeight = this->ui->frAddressList->height() -
            this->ui->saAddressList->height();

    height = ((QWidget*)this->parent()->parent())->height() -
            this->headerHeight;
    address_width = event->size().width() - this->ui->saAddressList->width();

    this->ui->frAddressList->resize(this->ui->saAddressList->width(), height);
    this->ui->saAddressList->resize(this->ui->saAddressList->width(),
                                    height - ignoredHeight);

    this->ui->frContentField->resize(address_width, height);


    return;
}

void QblDesktopContentFile::listResized()
{

    std::list<QblDesktopListFileRow*>::iterator iterator;
    int height = 0;
    int x = 0;

    for (iterator = this->identityList.begin();
         iterator != this->identityList.end(); iterator++) {
        (*iterator)->setGeometry(0, x, (*iterator)->width(), (*iterator)->height());
        height += (*iterator)->height();
        x += (*iterator)->height();
    }

    this->wdList->setMaximumSize(this->ui->frAddressList->width(), height);
    this->wdList->setMinimumSize(this->ui->frAddressList->width(), height);
    this->ui->saAddressList->setWidget(this->wdList);


    return;
}

void QblDesktopContentFile::onFileChanged(QblJsonMainConfigShare *upload)
{
    std::list<QblDesktopListFileRow*>::iterator iterator;

    if (this->client->getContentChanged() == false) {
        for (iterator = this->identityList.begin();
             iterator != this->identityList.end(); iterator++) {
            (*iterator)->setActive(upload);
        }
    }


    return;
}

void QblDesktopContentFile::onFileClicked(QblJsonMainConfigShare *upload)
{
    QblDesktopFContent *oldContent;
    oldContent = this->content;

    this->content = new QblDesktopFContent(QblContent::NONE,upload,this->ui->frContentField);
    this->content->resize(this->ui->frContentField->width(), this->ui->frContentField->height());
    this->content->show();


    if(oldContent != NULL) {
        oldContent->hide();
        delete oldContent;
    }

    return;

}

