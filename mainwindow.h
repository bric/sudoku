/****************************************************************************
 * 
 *  This file may be used under the terms of the GNU General Public
 *  License version 2.0 as published by the Free Software Foundation
 *  and appearing in the file LICENSE.GPL included in the packaging of
 *  this file.
 * 
 *  author:  Andreas Bricelj
 *  history: initial version 1.0  09/21/2005
 * 
 * ****************************************************************************/

#ifndef __MAINWINDOW__
#define __MAINWINDOW__
#include <QtCore>
#include <QtGui>

class Element;
class Field;
class GameControl;

#define SUDOKU_VERSION "sudoku V1.0"

class MainWindow : public QMainWindow {
    Q_OBJECT

    Field*        field;
    GameControl*  control;
    QSpinBox*     gameSelector;
    public:
        MainWindow(); 
        Element* getElement(int row, int column);

    public slots:
    void newGamePressed();
    void solveGamePressed();
    void hintPressed();
    void enterGamePressed();
    void helpPressed();
    void aboutPressed();
    void optionsPressed();
    void elementChanged(int r, int c, int value);

    private:
    void createActions();
    void createMenus();

    QMenu *gameMenu;
    QMenu *helpMenu;
    QAction *newAct;
    QAction *enterAct;
    QAction *solveAct;
    QAction *optionsAct;
    QAction *aboutAct;
    QAction *helpAct;
    QAction *quitAct;

};
#endif
