#include "qbl-desktop-addnewcontact.h"
#include "ui_qbl-desktop-addnewcontact.h"
#include "qbl-json-main-config-contact.h"

QblDesktopAddNewContact::QblDesktopAddNewContact(std::list<QblDesktopAddressIdentity *> identityList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QblDesktopAddNewContact), identityList(identityList)
{
    ui->setupUi(this);
    std::list<QblDesktopAddressIdentity *>::iterator iterator;
    for(iterator = this->identityList.begin(); iterator != this->identityList.end(); iterator++) {
        this->ui->cbIdentities->addItem(QString::fromStdString((*iterator)->getAlias()));
    }
}

QblDesktopAddNewContact::~QblDesktopAddNewContact()
{
    delete ui;
}

void QblDesktopAddNewContact::accept() 
{
    Qbl *qbl = Qbl::getInstance();
    QblMainConfig *config = qbl->getConfig();
    std::list<QblDesktopAddressIdentity *>::iterator iterator;
    iterator = this->identityList.begin();
    std::advance(iterator, this->ui->cbIdentities->currentIndex());
    std::string str = ((QblDesktopAddressIdentity *)(*iterator))->getPublicKey();
    QblJsonMainConfigContact *contact = config->addContact(this->ui->leAlias->text().toStdString(), this->ui->leInbox->text().toStdString(), this->ui->lePublicKey->text().toStdString(), str);
    qbl->getConfig()->configIsChanged();
    ((QblDesktopAddressIdentity *)(*iterator))->addContact(contact);

    this->done(0);
    return;
}

void QblDesktopAddNewContact::reject()
{
    this->done(0);
    return;
}
