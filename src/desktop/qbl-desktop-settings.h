#ifndef QBLDESKTOPSETTINGS_H
#define QBLDESKTOPSETTINGS_H

#include <QFrame>
#include <QLayout>

#include "qbl-desktop-content-settings.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-settings-identity.h"
#include "qbl-client.h"
#include "qbl-desktop-config-preferences.h"
#include "qbl-desktop-config-drop_servers.h"


namespace Ui {

class QblDesktopSettings;
}

class QblDesktopSettings: public QblDesktopContentSettings {
    Q_OBJECT
public:

    explicit QblDesktopSettings(QWidget *parent = 0);
    ~QblDesktopSettings();

public slots:

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);
private:

    QblDesktopConfigPreferences *preferences;
    QblDesktopConfigDropServers *dropServers;



private slots:

    void onPreferencesClicked();
    void onDropServersClicked();

signals:

};

#endif // QBLDESKTOPSETTINGS_H
