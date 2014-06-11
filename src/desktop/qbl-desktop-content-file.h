


#ifndef QBLDESKTOPCONTENTFILE_H
#define QBLDESKTOPCONTENTFILE_H

#include <QFrame>
#include <QLayout>

#include "qbl-content.h"
#include "qbl-desktop-list-identity.h"
#include "qbl-desktop-settings-identity.h"
#include "qbl-client.h"
#include "qbl-desktop-fcontent.h"
#include "qbl-desktop-content.h"
#include "qbl-desktop-list-file-row.h"

namespace Ui {

class QblDesktopContentFile;
}

class QblDesktopContentFile : public QblDesktopContent {
    Q_OBJECT

public:
    explicit QblDesktopContentFile(QWidget *parent = 0);
    ~QblDesktopContentFile();
    void changed();

private:
    std::list<QblDesktopListFileRow*> identityList;
    QblDesktopListFileRow *item = NULL;
    void sortIdentitiesByAlias();
    QblDesktopFContent *content = NULL;
protected:
    void resizeEvent(QResizeEvent *event);

private slots:
    void listResized();
    void onFileChanged(QblJsonMainConfigShare *upload);
    void onFileClicked(QblJsonMainConfigShare *upload);



};

#endif // QBLDESKTOPCONTENTFILE_H
