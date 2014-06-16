#ifndef QBL_DESKTOP_CONFIG_DROPSERVERS_H
#define QBL_DESKTOP_CONFIG_DROPSERVERS_H

#include <QWidget>
#include "config/qbl-json-main-config-dropserver-array.h"

namespace Ui {
class QblDesktopConfigDropServers;
}

class QblDesktopConfigDropServers : public QWidget
{
    Q_OBJECT
public:
    explicit QblDesktopConfigDropServers(QWidget *parent = 0);
    ~QblDesktopConfigDropServers();

private slots:
    void on_edit_clicked();

    void on_save_clicked();

    void on_cancel_clicked();


signals:

public slots:


private:
    Ui::QblDesktopConfigDropServers *ui;
    QblJsonMainConfigDropServerArray *dropservers;

    void initContent();

    void initEdits();

    void storeChanges();
};

#endif // QBL_DESKTOP_CONFIG_DROPSERVERS_H
