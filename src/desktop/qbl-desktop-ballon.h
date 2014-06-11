/**
 * @file		qbl-desktop-ballon.h
 * @brief		Message ballon for the desktop application (Header file)
 * @author		Michael Ott <michael@king-coder.de>
 *
 * copyright:	(C) 2014 by Qabel GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __QBL_DESKTOP_BALLON_H__
#define __QBL_DESKTOP_BALLON_H__

#include <QWidget>

namespace Ui {
class QblDesktopBallon;
}

class QblDesktopBallon : public QWidget
{
    Q_OBJECT

public:
    explicit QblDesktopBallon(std::string message, time_t timestamp, QWidget *parent = 0);
    ~QblDesktopBallon();

    void setText();

private:
    Ui::QblDesktopBallon *ui;
    std::string message;
    time_t timestamp;
};

#endif // __QBL_DESKTOP_BALLON_H__
