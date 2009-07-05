/****************************************************************************
 * 
 *  This file may be used under the terms of the GNU General Public
 *  License version 2.0 as published by the Free Software Foundation
 *  and appearing in the file LICENSE.GPL included in the packaging of
 *  this file.
 * 
 *  author:  Andreas Bricelj
 *  history: initial version 1.0  09/21/2005
 *           several updates 1.1  09/12/2006
 * 
 * ****************************************************************************/

#include <QtCore>
#include <QtGui>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    QString locale = QLocale::system().name();

    QTranslator translator;
    if (!translator.load(QString("sudoku_") + locale))
      translator.load(QString("sudoku_") + locale,"/usr/lib/");
    app.installTranslator(&translator);
 
    QCoreApplication::setOrganizationName("seafrog");
    QCoreApplication::setApplicationName("sudoku");

    MainWindow window;
    window.show();
    return app.exec();
}
