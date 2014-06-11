#ifndef QBLDESKTOPCONTENTSETTINGS_H
#define QBLDESKTOPCONTENTSETTINGS_H



#include <QFrame>
#include <QLayout>

#include "qbl-content.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-settings-identity.h"
#include "qbl-client.h"
#include "qbl-desktop-content.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the address book
 */
class QblDesktopContentSettings;
}

/**
 * Class QblDesktopContent: Address book for the desktop application
 * @brief The QblDesktopContent class
 */
class QblDesktopContentSettings: public QblDesktopContent {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopContentSettings
     * @param parent
     */
    explicit QblDesktopContentSettings(QWidget *parent = 0);
    ~QblDesktopContentSettings();

    /**
     * This function have to call when there are changes on the address book
     * @todo delete old content
     * @brief changed
     */
    void changed();


public slots:

protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);
private:
    std::list<QblDesktopSettingsIdentity*> mainSettingsCatagories; /**< List of all
                                                       identity widgets */
    QblDesktopSettingsIdentity *item;

private slots:
    void onListIdentityClicked(int id, bool collapse);
    /**
     * Handle the resize from the list (collapsed ist pressed=
     * @brief listResized
     */
    void listResized();
    /**
     * Handle when an address of the list is changed
     * @todo check whether address is changed before override
     * @brief onAddressClicked
     * @param contact
     */
    void onSettingChanged(int category, int id);
    /**
     * Handle when an address of the list is clicked
     * @todo check whether address is changed before override
     * @brief onAddressClicked
     * @param contact
     */
    void onSettingClicked(int category,int id);

signals:

    void cfg_Clicked(int category, int id);
};



#endif // QBLDESKTOPCONTENTSETTINGS_H
