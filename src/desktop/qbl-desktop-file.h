#ifndef QBLDESKTOPFILE_H
#define QBLDESKTOPFILE_H


#include "qbl-desktop-content-file.h"
#include "qbl-client.h"
#include "qbl-desktop-fcontent.h"

namespace Ui {
class QblDesktopFile;
}

class QblDesktopFile: public QblDesktopContentFile {
    Q_OBJECT

public:
    explicit QblDesktopFile(QWidget *parent = 0);
    ~QblDesktopFile();


private:



};

#endif // QBLDESKTOPFILE_H
