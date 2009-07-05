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

#include "gamecontrol.h"
#include "element.h"
#include <stdlib.h>

GameControl::GameControl(MainWindow* _window): 
window(_window), puzzleNr(0),  startTime(), state(init)
{
    timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerExpired()));
    window->statusBar()->showMessage(SUDOKU_VERSION);
}

void GameControl::newGame(int n, int hints) 
{
    state=generate;
    if (n!=0) {
        puzzleNr=n;
    } else {
        srand(QTime::currentTime().msecsTo(QTime()));
        puzzleNr=rand()%100000;
    }
    for (int r=0;r<9;r++)
        for (int c=0;c<9;c++) {
            window->getElement(r,c)->setValue(0);
            window->getElement(r,c)->setUnchangable();
            window->getElement(r,c)->setPosVal(0);
            window->getElement(r,c)->setCorrect();
        }
    window->statusBar()->showMessage(tr("please wait ..."));
    QCursor cursor=window->cursor();
    window->setCursor(Qt::WaitCursor);   
    puzzle.generate(puzzleNr);
    for (int r=0;r<9;r++)
        for (int c=0;c<9;c++) {
            window->getElement(r,c)->setValue(puzzle.get(r,c));
            if (puzzle.get(r,c))
                window->getElement(r,c)->setUnchangable();
            else
                window->getElement(r,c)->setChangable();
            window->getElement(r,c)->setPosVal(0);
            window->getElement(r,c)->setCorrect();
        }
    puzzle.solve();
    while ((hints--)>0)
      this->getHint();
    window->setCursor(cursor);
    startTime.start();
    timer->start(1000);
    timerExpired();
    state=playing;
}

void GameControl::getHint()
{
  int numhints=0;
  if (state==playing || state==generate) {
    for (int r=0;r<9;r++)
      for (int c=0;c<9;c++) {
        if ((window->getElement(r,c)->getValue()!=0) 
            &&(puzzle.get(r,c)!=window->getElement(r,c)->getValue())
            &&(!window->getElement(r,c)->isWrong())) {
          window->getElement(r,c)->setWrong();
          numhints++;
        } 
      }
    if (numhints==0)
      for (int r=0;r<9;r++)
        for (int c=0;c<9;c++) {
          if (window->getElement(r,c)->isWrong()) {
            window->getElement(r,c)->setValue(puzzle.get(r,c));
            window->getElement(r,c)->setCorrect();
            numhints++;
            r=9; c=9;
          }
        }
    if (numhints==0) {
      int ms=-1;
      int max=9;
      for (int s=0;s<9;s++) {
        int sum=0;
        for (int r=0; r<3; r++)
          for (int c=0; c<3; c++)
            if (window->getElement((s/3)*3+r,(s%3)*3+c)->getValue()>0)
              sum++;
        if (sum<max) {
          ms=s;
          max=sum;
        }
      }
      if (ms>=0) {
        int rv=rand()%3;
        for (int r=0; r<3; r++)
          for (int c=0; c<3; c++)
            if (window->getElement((ms/3)*3+(r+rv)%3,(ms%3)*3+(c+rv)%3)->getValue()==0) {
              window->getElement((ms/3)*3+(r+rv)%3,(ms%3)*3+(c+rv)%3)->
                setValue(puzzle.get((ms/3)*3+(r+rv)%3,(ms%3)*3+(c+rv)%3));
              if (state==generate) 
                window->getElement((ms/3)*3+(r+rv)%3,(ms%3)*3+(c+rv)%3)->setUnchangable();
              numhints++;
              r=3; c=3;
            }
      }
    }
    if (numhints>0 && state==playing) {
      startTime=startTime.addSecs(-30*numhints);
      timerExpired();
    }
  }
}

int GameControl::getValue(int r, int c)
{
  return window->getElement(r,c)->getValue();
}

void GameControl::editGame() 
{
    timer->stop();
    window->statusBar()->showMessage(SUDOKU_VERSION);
    state=edit;
    for (int r=0;r<9;r++)
        for (int c=0;c<9;c++) {
            window->getElement(r,c)->setValue(0);
            window->getElement(r,c)->setChangable();
            window->getElement(r,c)->setPosVal(0x1ff);
            window->getElement(r,c)->setCorrect();
        }
}


void GameControl::solveGame() 
{
    timer->stop();
    if (state==edit) {
        for (int r=0;r<9;r++)
            for (int c=0;c<9;c++) 
                puzzle.set(r,c,window->getElement(r,c)->getValue());
        int numSolutions=puzzle.solve(true);
        if (numSolutions==1) {
            for (int r=0;r<9;r++)
                for (int c=0;c<9;c++) 
                    if (window->getElement(r,c)->getValue()!=0) 
                        window->getElement(r,c)->setUnchangable();
            puzzle.solve(false);
            for (int r=0;r<9;r++)
                for (int c=0;c<9;c++) {
                    if (window->getElement(r,c)->getValue()==0) {
                        window->getElement(r,c)->setValue(puzzle.get(r,c));
                    }
                }
            state=init;
        } else if (numSolutions==0) {
            QMessageBox::information(window,SUDOKU_VERSION,
                tr("no solution for this puzzle"));
        } else {
            QMessageBox::information(window,SUDOKU_VERSION,
                tr("more than one solution for this puzzle"));
        }
    } else if (state==playing || state==solving || state==correcting) {
        bool correct=true;
        if (state==playing)
            for (int r=0;r<9;r++)
                for (int c=0;c<9;c++)
                    if (window->getElement(r,c)->getValue()==0)
                        state=solving;
        for (int r=0;r<9;r++)
            for (int c=0;c<9;c++) {
                if (window->getElement(r,c)->getValue()==0) {
                    window->getElement(r,c)->setValue(puzzle.get(r,c));
                    window->getElement(r,c)->setCorrect();
                } else if (puzzle.get(r,c)==window->getElement(r,c)->getValue()) {
                    window->getElement(r,c)->setCorrect();
                } else {
                    if (state==correcting) {
                        window->getElement(r,c)->setValue(puzzle.get(r,c));
                        window->getElement(r,c)->setCorrect();
                    } else {
                        window->getElement(r,c)->setWrong();
                        correct=false;
                    }
                }
            }
        if (state==playing) {
            if (correct) {
                QMessageBox::information(window,SUDOKU_VERSION,
                    tr("you made it !!!"));
                state=finished;
            } else {
                QMessageBox::information(window,SUDOKU_VERSION,
                    tr("oops, there is a mistake ..."));
                state=correcting;
            }
        } else if (state==solving && !correct) {
            state=correcting;
        } else {
            state=finished;
        }
    }
}


void GameControl::elementChanged(int r, int c, int value) 
{
    if (state==playing) {
      bool finished=true;
      for (int r=0; r<9; r++)
          for (int c=0; c<9; c++)
              if (window->getElement(r,c)->getValue()==0) {
                finished=false;
                if (window->getElement(r,c)->isWrong())
                  window->getElement(r,c)->setCorrect();
              }
      if (!finished)
        return;
      int reply=QMessageBox::question(window,SUDOKU_VERSION,
              tr("are you finished"),
              QMessageBox::Yes,
              QMessageBox::No);
      if (reply==QMessageBox::Yes) {
          solveGame();
      }
    } else if (state==edit) {
        if (value!=0){
            int sr=3*(r/3);
            int sc=3*(c/3);
            for (int i=0; i<9; i++) {
                Element* e=window->getElement(r,i);
                e->setPosVal(e->getPosVal()&~(1<<(value-1)));
                e=window->getElement(i,c);
                e->setPosVal(e->getPosVal()&~(1<<(value-1)));
                e=window->getElement(sr+i/3,sc+i%3);
                e->setPosVal(e->getPosVal()&~(1<<(value-1)));
            } 
        } else {
            int posField[9][9];
            for (int r=0; r<9; r++)
                for (int c=0; c<9; c++)
                    posField[r][c]=0x1ff;
            for (int r=0; r<9; r++)
                for (int c=0; c<9; c++)
                    if (window->getElement(r,c)!=0)
                        for (int i=0; i<9; i++) {
                            posField[r][i]&=~(1<<(window->getElement(r,c)->getValue()-1));
                            posField[i][c]&=~(1<<(window->getElement(r,c)->getValue()-1));
                            posField[3*(r/3)+i/3][3*(c/3)+i%3]&=~(1<<(window->getElement(r,c)->getValue()-1));
                        }
            for (int r=0; r<9; r++)
                for (int c=0; c<9; c++)
                    window->getElement(r,c)->setPosVal(posField[r][c]);
        }
    }
}

void GameControl::timerExpired() 
{
    window->statusBar()->showMessage(
        QString(tr("current game: %1 : elapsed time %2"))
            .arg(puzzleNr)
            .arg(QTime().addMSecs(startTime.elapsed()).toString("mm:ss")));
}
