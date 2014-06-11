#include <QResizeEvent>

#include "qbl-desktop-settings.h"
#include "ui_qbl-desktop-content.h"
#include "qbl-desktop-list-identity.h"

#include "qbl.h"
#include "qbl-json-main-config-identity.h"
#include "qbl-json-main-config-identity-array.h"

QblDesktopSettings::QblDesktopSettings(QWidget *parent) :
    QblDesktopContentSettings(parent)
{
    this->preferences = NULL;
    this->dropServers = NULL;

    connect(this,SIGNAL(preferencesClicked()),
            this,SLOT(onPreferencesClicked()));
    connect(this,SIGNAL(dropServersClicked()),
            this,SLOT(onDropServersClicked()));

    return;
}

QblDesktopSettings::~QblDesktopSettings()
{
    if(this->preferences != NULL) {
        delete (this->preferences);
    }
    return;
}

void QblDesktopSettings::onPreferencesClicked()
{
    QblDesktopConfigPreferences *oldContent;
    oldContent = this->preferences;

    this->preferences = new QblDesktopConfigPreferences(this->ui->frContentField);
    this->preferences->show();

    if(oldContent != NULL) {
        oldContent->hide();
        delete oldContent;
    }

    return;
}

void QblDesktopSettings::resizeEvent(QResizeEvent *event)
{
    QblDesktopContentSettings::resizeEvent(event);
    
    this->ui->frContentField->resize(event->size().width() - this->ui->frAddressList->width(), event->size().height());

    return;
}

void QblDesktopSettings::onDropServersClicked()
{
    return;
}

