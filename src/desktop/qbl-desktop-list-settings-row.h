#ifndef QBLDESKTOPLISTSETTINGSROW_H
#define QBLDESKTOPLISTSETTINGSROW_H

#include <QWidget>

#include "config/qbl-json-main-config-contact.h"

#include "qbl-desktop-list-item.h"
#include "qbl-client.h"




namespace Ui {

class QblDesktopListSettingsRow;
}

class QblDesktopListSettingsRow : public QWidget
{
    Q_OBJECT

public:
    explicit QblDesktopListSettingsRow(std::string category_name,
            int id, int category, QWidget *parent = 0);

    ~QblDesktopListSettingsRow();


    void setText(QString text);

    QString text();

    void setActive(int id, int category);



protected:
        void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::QblDesktopListSettingsRow *ui;
    int id;
    int category;
    QblClient *client;

    void setCss();

signals:
    void changed(int category, int id);
    void clicked(int category, int id);

};

#endif  //QBLDESKTOPLISTSETTINGSROW_H
