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

#include "mainwindow.h"
#include "element.h"
#include "puzzle.h"
#include "field.h"
#include "gamecontrol.h"

#include <QtCore>
#include <QtGui>
#include <stdlib.h>

MainWindow::MainWindow()
{
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *widget1;
    QWidget *widget2;
    QWidget *widget3;
    QWidget *layoutWidget;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QPushButton *newPushButton;
    QPushButton *editPushButton;
    QPushButton *solvePushButton;
    
    this->resize(QSize(424, 455).expandedTo(this->minimumSizeHint()));
    QSizePolicy sizePolicy((QSizePolicy::Policy)7, (QSizePolicy::Policy)7);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(this->sizePolicy().hasHeightForWidth());
    this->setSizePolicy(sizePolicy);
    centralWidget = new QWidget(this);
    widget = new QWidget(centralWidget);
    widget1 = new QWidget(centralWidget);
    widget2 = new QWidget(centralWidget);
    widget3 = new QWidget(centralWidget);
    layoutWidget = new QWidget(centralWidget);
    QGridLayout* mainLayout=new QGridLayout(centralWidget);
    mainLayout->setSpacing(20);
    mainLayout->setMargin(20);
    mainLayout->addWidget(layoutWidget);
    vboxLayout = new QVBoxLayout(layoutWidget);
    vboxLayout->setSpacing(6);
    vboxLayout->setMargin(0);
    field = new Field(layoutWidget);
    QSizePolicy sizePolicy1((QSizePolicy::Policy)7, (QSizePolicy::Policy)7);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(field->sizePolicy().hasHeightForWidth());
    field->setSizePolicy(sizePolicy1);
    field->setMinimumSize(QSize(400, 400));

    vboxLayout->addWidget(field);

    hboxLayout = new QHBoxLayout();
    hboxLayout->setSpacing(6);
    hboxLayout->setMargin(0);
    newPushButton = new QPushButton(layoutWidget);

    hboxLayout->addWidget(newPushButton);

    gameSelector = new QSpinBox(layoutWidget);
    gameSelector->setMinimum(0);
    gameSelector->setMaximum(99999);

    hboxLayout->addWidget(gameSelector);

    editPushButton = new QPushButton(layoutWidget);

    hboxLayout->addWidget(editPushButton);

    solvePushButton = new QPushButton(layoutWidget);

    hboxLayout->addWidget(solvePushButton);


    vboxLayout->addLayout(hboxLayout);

    this->setCentralWidget(centralWidget);
    this->setWindowTitle(QApplication::translate("MainWindow", SUDOKU_VERSION ));
    newPushButton->setText(QApplication::translate("MainWindow", "New"));
    editPushButton->setText(QApplication::translate("MainWindow", "Enter"));
    solvePushButton->setText(QApplication::translate("MainWindow", "Solve"));

    control=new GameControl(this);
    connect(newPushButton,SIGNAL(clicked()),this,SLOT(newGamePressed()));
    connect(solvePushButton,SIGNAL(clicked()),this,SLOT(solveGamePressed()));
    connect(editPushButton,SIGNAL(clicked()),this,SLOT(enterGamePressed()));
    for (int r=0; r<9; r++)
        for (int c=0; c<9; c++)
            connect(field->getElement(r,c),SIGNAL(valueChanged(int,int,int)),this,SLOT(elementChanged(int,int,int)));

   createActions(); 
   createMenus();
   setWindowIcon(QIcon(":/images/sudoku.png"));
}

Element* MainWindow::getElement(int row, int column) 
{
    return field->getElement(row,column);
}

void MainWindow::newGamePressed()
{
    control->newGame(gameSelector->value());
//    gameSelector->setValue(gameSelector->value()+1);
}

void MainWindow::enterGamePressed()
{
    control->editGame();
}

void MainWindow::solveGamePressed()
{
    control->solveGame();
}

void MainWindow::hintPressed()
{
}

void MainWindow::elementChanged(int r, int c, int value)
{
    control->elementChanged(r,c,value);
}


void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcut(tr("Ctrl+N"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newGamePressed()));

    solveAct = new QAction(tr("&Solve"), this);
    solveAct->setShortcut(tr("Ctrl+S"));
    connect(solveAct, SIGNAL(triggered()), this, SLOT(solveGamePressed()));

    enterAct = new QAction(tr("&Enter"), this);
    enterAct->setShortcut(tr("Ctrl+E"));
    connect(enterAct, SIGNAL(triggered()), this, SLOT(enterGamePressed()));
    
//    optionsAct = new QAction(tr("&Options"), this);
//    optionsAct->setShortcut(tr("Ctrl+O"));
//    connect(optionsAct, SIGNAL(triggered()), this, SLOT(optionsPressed()));

    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setShortcut(tr("Ctrl+A"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(aboutPressed()));

    helpAct = new QAction(tr("&Help"), this);
    helpAct->setShortcut(tr("Ctrl+H"));
    connect(helpAct, SIGNAL(triggered()), this, SLOT(helpPressed()));
    
    quitAct = new QAction(tr("&Quit"), this);
    quitAct->setShortcut(tr("Ctrl+Q"));
    connect(quitAct, SIGNAL(triggered()), this, SLOT(close()));

}

void MainWindow::createMenus()
{
   gameMenu=menuBar()->addMenu(tr("&Game"));
   gameMenu->addAction(newAct);
   gameMenu->addAction(enterAct);
   gameMenu->addAction(solveAct);
//   gameMenu->addAction(optionsAct);
   gameMenu->addAction(quitAct);
   

   helpMenu=menuBar()->addMenu(tr("&Help"));
   helpMenu->addAction(helpAct);
   helpMenu->addAction(aboutAct);

}

void MainWindow::optionsPressed()
{

}

void MainWindow::helpPressed()
{
    QMessageBox::about(this,SUDOKU_VERSION,
"<b>Rules:</b><br>Fill the fields with digits 1-9; every digit may occur only once in a row, a column "
"and in one of the 9 3x3 square fields."
"<p><b>Game modes:</b><br><i>regular game:</i>"
"<br>select a puzzle number (0 means random), press <b>new</b> and play the game. " 
"You may press <b>solve</b> to see the solution."
"<br><br><i>edit mode:</i>"
"<br>press <b>enter</b> and enter your game. You will get the solution by pressing <b>solve</b>."
"<p><b>Control:</b><br>The game is fully controlled by the mouse"
"<br><i>left-klick</i> on an empty field brings up all digits; you may choose one digit by a left-klick or exclude some "
"numbers which are not possible from your point of view by using the right mouse button."
"<br><i>right-klick</i> on an empty field gives you an empty field; you may populate it with the possibilities you "
"see for this field.<br><b>Mac OSX hint:</b> <i>right-click = ctrl+klick</i> <p>");
}

void MainWindow::aboutPressed()
{
    QMessageBox::about(this,SUDOKU_VERSION,"<p>by Andreas Bricelj"
            "<p>you may use, distribute and copy this program under the <br>GNU PUBLIC LICENSE Version 2, June 1991."
            "<p>the source code is available at <p><b>http://www.seafrog.de/sudoku</b>"
            "<p>bric@seafrog.de");
}
