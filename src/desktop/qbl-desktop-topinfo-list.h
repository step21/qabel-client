#ifndef QBLDESKTOPTOPINFOLIST_H
#define QBLDESKTOPTOPINFOLIST_H

#include <QWidget>
#include <QVBoxLayout>

namespace Ui {
class QblDesktopTopInfoList;
}

class QblDesktopTopInfoList : public QWidget
{
    Q_OBJECT
    
public:
    explicit QblDesktopTopInfoList(QWidget *parent = 0);
    ~QblDesktopTopInfoList();
    
    void addToInfoList();
    
private:
    Ui::QblDesktopTopInfoList *ui;
};

#endif // QBLDESKTOPTOPINFOLIST_H
