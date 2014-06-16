#ifndef QBLDESKTOPSETTINGSCONTENTPREFERENCES_H
#define QBLDESKTOPSETTINGSCONTENTPREFERENCES_H



#include "config/qbl-json-main-config-preferences.h"

#include <QWidget>

namespace Ui {
class QblDesktopConfigPreferences;
}

class QblDesktopConfigPreferences : public QWidget
{
    Q_OBJECT
public:
    explicit QblDesktopConfigPreferences(QWidget *parent = 0);
    ~QblDesktopConfigPreferences();
private slots:
    void on_edit_clicked();

    void on_save_clicked();

    void on_cancel_clicked();

signals:
    
protected:
    /**
     * This handler will called when the application will be resized;
     * @brief resizeEvent
     * @param event Resize event object
     */
    void resizeEvent(QResizeEvent *event);

public slots:

private:
    Ui::QblDesktopConfigPreferences *ui; /**< Object handle the UI stuff */
    QblJsonMainConfigPreferences *preferences;


    void initContent();

    void initEdits();

    void storeChanges();

};

#endif // QBLDESKTOPSETTINGSCONTENTPREFERENCES_H
