#ifndef QBLDESKTOPCONFIGLIST_H
#define QBLDESKTOPCONFIGLIST_H

#include <QWidget>
#include "qbl-json-main-config-contact.h"
#include "qbl-desktop-list-item.h"
#include "qbl-client.h"


namespace Ui {

class QblDesktopConfigList;
}


class QblDesktopConfigList : public QblDesktopListItem
{
    Q_OBJECT

public:
    explicit QblDesktopConfigList(QblJsonMainConfigContact *contact,
            int id, QWidget *parent = 0);
    ~QblDesktopConfigList();

};
#endif // QBLDESKTOPCONFIGLIST_H
