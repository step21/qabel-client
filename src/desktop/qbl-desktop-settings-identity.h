#ifndef QBLDESKTOPSETTINGSITENTITY_H
#define QBLDESKTOPSETTINGSITENTITY_H

#include <QFrame>
#include <QVBoxLayout>

#include "config/qbl-json-main-config-identity.h"
#include "config/qbl-json-main-config-contact.h"

#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-list-settings-row.h"

class QblDesktopSettingsIdentity: public QWidget {
    Q_OBJECT

public:
    explicit QblDesktopSettingsIdentity(int settingsId,
            QWidget *parent = 0);
    ~QblDesktopSettingsIdentity();

    void setActive(int id, int category);

protected:

    void resizeEvent(QResizeEvent *event);

private:
    int settingsId;
    QblJsonMainConfigIdentity *obj;
    std::string categoryName ="";
    QFrame *frame;
    QVBoxLayout *layout;
    QblDesktopListIdentity *identity;
    std::list<QblDesktopListSettingsRow *> items;

    void setHeight();

private slots:
    //expand if there are subcategorys(items)
    void onListCategoryClicked(bool collapse);


    void onListRowChanged(int category, int id);

    void onListRowClicked(int category, int id);

signals:
    void collapsedClicked();
    void settingChanged(int category, int id);
    void settingClicked(int category, int id);
};

#endif // QBLDESKTOPSETTINGSITENTITY_H
