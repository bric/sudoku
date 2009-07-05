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

#ifndef __MAINWINDOW__
#define __MAINWINDOW__
#include <QtCore>
#include <QtGui>

class Element;
class Field;
class GameControl;

#define SUDOKU_VERSION "sudoku V1.1a"

class MainWindow : public QMainWindow {
    Q_OBJECT

    Field*        field;
    GameControl*  control;
    QSpinBox*     gameSelector;
    public:
        MainWindow(); 
        Element* getElement(int row, int column);
        virtual void closeEvent(QCloseEvent *event);

    public slots:
    void newGamePressed();
    void solveGamePressed();
    void hintGamePressed();
    void enterGamePressed();
    void exportGamePressed();
    void helpPressed();
    void aboutPressed();
    void elementChanged(int r, int c, int value);

    private:
    void createActions();
    void createMenus();
    void writeGameHtml(QString filename);
    void writeGamePDF(QString filename);

    QMenu *fileMenu;
    QMenu *gameMenu;
    QMenu *levelMenu;
    QMenu *helpMenu;
    QAction *newAct;
    QAction *enterAct;
    QAction *solveAct;
    QAction *exportAct;
    QAction *hintAct;
    QAction *expertAct;
    QAction *normalAct;
    QAction *beginnerAct;
    QActionGroup *levelGroup;
    QAction *aboutAct;
    QAction *helpAct;
    QAction *quitAct;

};
#endif
