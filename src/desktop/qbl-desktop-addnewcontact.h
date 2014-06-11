#ifndef QBLDESKTOPADDNEWCONTACT_H
#define QBLDESKTOPADDNEWCONTACT_H

#include <QDialog>
#include "qbl-desktop-address-identity.h"

namespace Ui {
class QblDesktopAddNewContact;
}

class QblDesktopAddNewContact : public QDialog
{
    Q_OBJECT
    
public:
    explicit QblDesktopAddNewContact(std::list<QblDesktopAddressIdentity *> identityList, QWidget *parent = 0);
    ~QblDesktopAddNewContact();
    
    /**
     * Handle when accept button is clicked
     * @brief accept
     */
    void accept();
    /**
     * Handle when cancel button is clicked
     * @brief reject
     */
    void reject();
    
private:
    Ui::QblDesktopAddNewContact *ui;
    std::list<QblDesktopAddressIdentity *> identityList;
};

#endif // QBLDESKTOPADDNEWCONTACT_H
