/****************************************************************************
 * 
 *  This file may be used under the terms of the GNU General Public
 *  License version 2.0 as published by the Free Software Foundation
 *  and appearing in the file LICENSE.GPL included in the packaging of
 *  this file.
 * 
 *  author:  Andreas Bricelj
 *  history: initial version 1.0  09/21/2005
 *           1.0.1 10/02/2005 change qtcore -> QtCore, qtgui -> QtGui
 *           several updates 1.1  09/12/2006
 * 
 * ****************************************************************************/

#ifndef __GAMECONTROL_H__
#define __GAMECONTROL_H__

#include "puzzle.h"
#include <QtCore>
#include <QtGui>
#include "mainwindow.h"

class GameControl: public QObject {
    Q_OBJECT
   MainWindow* window;
   int    puzzleNr;
   Puzzle puzzle;
   QTimer* timer;
   QTime  startTime;
   enum { init, edit, generate, playing, finished, solving, correcting } state; 
    public: 
      GameControl(MainWindow* window);
      void newGame(int n, int hints);
      void solveGame();
      void editGame();
      void getHint();
      void elementChanged(int r, int c, int value);
      int  getValue(int r, int c);

      public slots:
          void timerExpired();
};

#endif
