#ifndef QBLDESKTOPCONTENTCHAT_H
#define QBLDESKTOPCONTENTCHAT_H


#include <QFrame>
#include <QLayout>

#include "qbl-content.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-address-identity.h"
#include "qbl-client.h"
#include "qbl-desktop-content.h"

/**
 * With QtCreator generated UI
 */
namespace Ui {
/**
 * Qt created class for the address book
 */
class QblDesktopContentChat;
}

/**
 * Class QblDesktopContent: Address book for the desktop application
 * @brief The QblDesktopContent class
 */
class QblDesktopContentChat: public QblDesktopContent {
    Q_OBJECT
public:
    /**
     * Constructor
     * @brief QblDesktopContent
     * @param parent
     */
    explicit QblDesktopContentChat(QWidget *parent = 0);
    ~QblDesktopContentChat();

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
    std::list<QblDesktopAddressIdentity*> identityList; /**< List of all
                                                        identity widgets */
    QblDesktopAddressIdentity *item;
    
    /**
     * This function sorts the identity list by alias
     * @brief sortByAlias
     */
    void sortIdentitiesByAlias();

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
    void onAddressChanged(QblJsonMainConfigContact *contact);
    /**
     * Handle when an address of the list is clicked
     * @todo check whether address is changed before override
     * @brief onAddressClicked
     * @param contact
     */
    void onAddressClicked(QblJsonMainConfigIdentity *identity,
                          QblJsonMainConfigContact *contact);

signals:

};

#endif // QBLDESKTOPCONTENTCHAT_H
