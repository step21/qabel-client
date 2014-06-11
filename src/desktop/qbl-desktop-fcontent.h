#ifndef QBLDESKTOPFCONTENT_H
#define QBLDESKTOPFCONTENT_H
#include <QWidget>
#include <QModelIndex>
#include <QList>
#include "qbl-client.h"
#include "qbl-content.h"


#include <QStandardItem>
#include <QStandardItemModel>
#include <QFileSystemModel>

namespace Ui {
class QblDesktopFContent;
}

class QblDesktopFContent : public QblContent
{
    Q_OBJECT
public:
    explicit QblDesktopFContent(QblContent::contentType type = QblContent::NONE, QblJsonMainConfigShare *share = NULL,
                                QWidget *parent = 0);
    ~QblDesktopFContent();
    void showDirectory();

signals:

public slots:

private slots:

    void on_pushButton_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void moveTo(const QString& path);
    void deleteItem();
    void contextMenu(const QPoint &pos);

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::QblDesktopFContent *ui;
    QFileSystemModel *filesys;
    QString root;
    QblJsonMainConfigShare *share = NULL;


};

#endif // QBLDESKTOPFCONTENT_H
