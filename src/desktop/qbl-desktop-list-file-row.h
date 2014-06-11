#ifndef QBLDESKTOPLISTFILEROW_H
#define QBLDESKTOPLISTFILEROW_H

#include <QWidget>

#include "qbl-desktop-list-item.h"
#include "qbl-client.h"

namespace Ui {
class QblDesktopListSettingsRow;
}

class QblDesktopListFileRow : public QWidget
{
    Q_OBJECT
public:
    explicit QblDesktopListFileRow(QblJsonMainConfigShare *obj,QWidget *parent = 0);
    ~QblDesktopListFileRow();

    void setText(QString text);

    QString text();

    void setActive(QblJsonMainConfigShare *upload);

protected:
        void mouseReleaseEvent(QMouseEvent* event);

private:
    Ui::QblDesktopListSettingsRow *ui;
    int id;
    int category;
    QblClient *client;
    QblJsonMainConfigShare *obj;

    void setCss();

signals:
    void changed(QblJsonMainConfigShare*);
    void clicked(QblJsonMainConfigShare*);

};

#endif // QBLDESKTOPLISTFILEROW_H
