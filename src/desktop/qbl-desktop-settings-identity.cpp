#include "qbl-json-main-config-contact-array.h"

#include "qbl-client.h"
#include "qbl-desktop-settings-identity.h"
#include "qbl-desktop-list-settings-row.h"

#include "qbl-desktop-settings-constants.h"

QblDesktopSettingsIdentity::QblDesktopSettingsIdentity(int settingsId, QWidget *parent) :
        QWidget(parent)
{
    this->settingsId=settingsId;
    int id = 0;

    QblClient *client = QblClient::getInstance();
    Qbl *qbl = Qbl::getInstance();
    QblDesktopListSettingsRow * item;

    switch(settingsId)
    {
    case MAINSETTINGS:      //Lists all Settings that doesnt have subelements with more option
        this->categoryName = "Main and connection settings";
        this->identity = new QblDesktopListIdentity(nullptr, true);
        this->items.push_back(new QblDesktopListSettingsRow("preferences",PREFERENCES,settingsId,parent));
        this->items.push_back(new QblDesktopListSettingsRow("shares",SHARES,settingsId,parent));
        break;

    case IDENTITYS:         //Creates list of identitys, begining with add-button with id -1
        this->categoryName="Identitys";
         this->identity = new QblDesktopListIdentity(nullptr, true);
        {

            item= new QblDesktopListSettingsRow("add identity",-1,settingsId,parent);
            this->items.push_back(item);
            std::list<QblJsonMainConfigIdentity*> identitys;
            QblJsonMainConfigIdentity* identity;
            identitys = qbl->getConfig()->getIdentities()->getList();
            foreach (identity,identitys)
            {
                item= new QblDesktopListSettingsRow(identity->getAlias(),id,settingsId,parent);
                this->items.push_back(item);
                id++;
            }

        }
        break;

    case DROPSERVER:        //Creates list of Dropservers, begining with add-button with id -1
        this->categoryName = "Drop server";
        this->identity = new QblDesktopListIdentity(nullptr, true);
        {

            item= new QblDesktopListSettingsRow("add DropServer",-1,settingsId,parent);
            this->items.push_back(item);
            std::list<QblJsonMainConfigDropServer*> dropservers;
            dropservers = qbl->getConfig()->getDropServers()->getList();
            foreach (QblJsonMainConfigDropServer* dropserver,dropservers)
            {
                item=new QblDesktopListSettingsRow(dropserver->getUrl(),id,settingsId,parent);
                this->items.push_back(item);
                id++;
            }
        }
        break;

     case BLOCKSERVERS:
        this->categoryName = "Block servers";
        this->identity = new QblDesktopListIdentity(nullptr, true);
        {

            item= new QblDesktopListSettingsRow("add Blockserver",-1,settingsId,parent);
            this->items.push_back(item);
            std::list<QblJsonMainConfigBlockServer*> blockservers;
            blockservers = qbl->getConfig()->getBlockServers()->getList();
            foreach (QblJsonMainConfigBlockServer* blockserver,blockservers)
            {
                item=new QblDesktopListSettingsRow(blockserver->getUrl(),id,settingsId,parent);
                this->items.push_back(item);
                id++;
            }
        }
        break;


    }
    this->identity->setText(QString::fromStdString(this->categoryName));
    this->identity->setStyleSheet(
            client->getCss().getStyleSheet("settings-category"));

    this->layout = new QVBoxLayout(this);
    this->layout->setSpacing(0);
    this->layout->setMargin(0);
    this->layout->setContentsMargins(0, 0, 0, 0);
    this->layout->addWidget(this->identity, 0, Qt::AlignTop);


    connect(this->identity, SIGNAL(collapsed(bool)), this,
            SLOT(onListCategoryClicked(bool)));

    //connect Signals to every item and add them to layout
    foreach(item ,items)
    {
        this->layout->addWidget(item);

        connect(item, SIGNAL(changed(int,int)),
                this, SLOT(onListRowChanged(int,int)));
        connect(item, SIGNAL(clicked(int,int)),
                this, SLOT(onListRowClicked(int,int)));

    }

    this->setHeight();

    return;
}


QblDesktopSettingsIdentity::~QblDesktopSettingsIdentity()
{
    return;
}

void QblDesktopSettingsIdentity::setActive(int id, int category)
{
    std::list<QblDesktopListSettingsRow *>::iterator iterator;
    for (iterator = this->items.begin(); iterator != this->items.end();
         iterator++) {
        (*iterator)->setActive(id,category);
    }

    return;
}

void QblDesktopSettingsIdentity::resizeEvent(QResizeEvent */*event*/)
{
    this->setHeight();

    return;
}

void QblDesktopSettingsIdentity::setHeight()
{
    int height;

    height = this->identity->height();
    if(this->items.size()>0)
    {
        if (this->identity->getCollapse() == false) {
            height += this->items.size() * 40;
        }
    }

    this->resize(this->identity->width(), height);

    return;
}

void QblDesktopSettingsIdentity::onListCategoryClicked(bool /*collapse*/)
{
    //expand the list, if there are items
    if(this->items.size()>0)
    {
        this->setHeight();
        emit(collapsedClicked());
    }
    return;
}

void QblDesktopSettingsIdentity::onListRowChanged(
        int category, int id)
{
    emit(settingChanged(category, id));

    return;
}

void QblDesktopSettingsIdentity::onListRowClicked(
        int category, int id)
{
    emit(settingClicked(category, id));

    return;
}
