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

#include "mainwindow.h"
#include "element.h"
#include "puzzle.h"
#include "field.h"
#include "gamecontrol.h"
#include "hpdf.h"
#include <setjmp.h>

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
    this->setWindowTitle(tr(SUDOKU_VERSION ));
    newPushButton->setText(tr("New"));
    editPushButton->setText(tr("Enter"));
    solvePushButton->setText(tr("Solve"));

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
    int hints=0;
    if (beginnerAct->isChecked())
      hints=8;
    else if (normalAct->isChecked())
      hints=4;
    control->newGame(gameSelector->value(),hints);
}

void MainWindow::enterGamePressed()
{
    control->editGame();
}


void MainWindow::writeGameHtml(QString filename)
{
  QFile file(filename);
  if (!file.open(QIODevice::WriteOnly)) {
    QMessageBox::warning(this,tr("sudoku"),
        tr("cannot write file %1:\n%2")
        .arg(file.fileName())
        .arg(file.errorString()));
    return;
  }
  QTextStream out(&file);
  out<<"<html><body>\n";
  out<<"<table border=0 cellspacing=1 cellpadding=0>\n";
  for (int qr=0;qr<3;qr++) {
    out<<"<tr>\n";
    for (int qc=0;qc<3;qc++) {
      out<<"<td>\n";
      out<<"<table border=1 cellspacing=0 cellpadding=0>\n";
      for (int r=qr*3;r<(qr+1)*3;r++) {
        out<<"<tr>\n";
        for (int c=qc*3;c<(qc+1)*3;c++) {
          int v=control->getValue(r,c);
          if (v)
            out<<"<td width=\"40\" height=\"40\" bgcolor=\"#aaaaaa\" align=\"center\" valign=\"center\">"
              "<font size=\"5\">"+QString::number(v)+"</font></td>\n";
          else
            out<<"<td width=\"40\" height=\"40\" align=\"center\" valign=\"center\">"
              "&nbsp;</td>\n";

        }
        out<<"</tr>\n";
      }
      out<<"</table>\n";
      out<<"</td>\n";
    }
    out<<"</tr>\n";
  }
  out<<"</table>\n";
  out<<"</body></html>\n";
}


//pdf generator specific definitions and error handler
static const int CELL_WIDTH = 20;
static const int CELL_HEIGHT = 20;
static const int PAGE_WIDTH = CELL_WIDTH*11;
static const int PAGE_HEIGHT = CELL_HEIGHT*11;

static jmp_buf env;
static void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void*)
{
    qDebug("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}

void MainWindow::writeGamePDF(QString filename)
{
    HPDF_Doc  pdf;
    HPDF_Font font;

    pdf = HPDF_NewEx (error_handler, NULL, NULL, 0, NULL);
    if (!pdf) {
        qDebug("error: cannot create PdfDoc object\n");
        return;
    }

    if (setjmp(env)) {
        HPDF_Free (pdf);
        return;
    }

    /* set compression mode */
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);

    /* Set page mode to use no outlines. */
    HPDF_SetPageMode(pdf, HPDF_PAGE_MODE_USE_NONE);

    /* get default font */
    font = HPDF_GetFont (pdf, "Helvetica", NULL);

    HPDF_Page page = HPDF_AddPage (pdf);

    HPDF_Page_SetWidth (page, PAGE_WIDTH);
    HPDF_Page_SetHeight (page, PAGE_HEIGHT);

    HPDF_Page_SetFontAndSize (page, font, 15);

    /* Draw lines. */
    for (int i = 0; i <= 9; i++) {
      if (i==3 || i==6) 
        HPDF_Page_SetLineWidth (page, 1.5);
      else
        HPDF_Page_SetLineWidth (page, 0.5);
      HPDF_Page_MoveTo (page, (i+1)*CELL_WIDTH, 10*CELL_HEIGHT);
      HPDF_Page_LineTo (page, (i+1)*CELL_WIDTH, CELL_HEIGHT);
      HPDF_Page_Stroke (page);

      HPDF_Page_MoveTo (page, 10*CELL_WIDTH, (i+1)*CELL_HEIGHT);
      HPDF_Page_LineTo (page, CELL_WIDTH, (i+1)*CELL_HEIGHT);
      HPDF_Page_Stroke (page);
    }

    for (int r=0; r<9; r++)
      for (int c=0; c<9; c++) {
            int v=control->getValue(r,c);
            if (v==0) 
              continue;
            HPDF_Page_BeginText (page);
            HPDF_Page_MoveTextPos (page, (c+1)*CELL_WIDTH+6,(9-r)*CELL_HEIGHT+5);
            HPDF_Page_ShowText (page, QString::number(v).toAscii());
            HPDF_Page_EndText (page);
      }

    HPDF_SaveToFile (pdf, filename.toAscii());
    HPDF_Free (pdf);
}



void MainWindow::exportGamePressed()
{
    QSettings settings;
    QString   filename;
    QString   filepath;
    QString   filters;
    QString   selectedfilter;

    if (settings.value("exporttype","PDF").toString()=="PDF")
      filters="PDF (*.pdf,*.PDF);;HTML (*.html,*.HTML)";
    else
      filters="HTML (*.html,*.HTML);;PDF (*.pdf,*.PDF)";
    filename=QFileDialog::getSaveFileName(this,
		    tr("choose an export filename"),
		    settings.value("exportpath",QDir::currentPath()).toString(),
		    filters,&selectedfilter);
    if (!filename.isEmpty()) {
      settings.setValue("exportpath",QFileInfo(filename).absolutePath());
      if (filename.toUpper().endsWith(".HTML")) {
        settings.setValue("exporttype","HTML");
        writeGameHtml(filename);
      } else if (filename.toUpper().endsWith(".PDF")) {
        settings.setValue("exporttype","PDF");
        writeGamePDF(filename);
      } else if (filename.length()!=0) {
        if (selectedfilter.startsWith("HTML")) {
          settings.setValue("exporttype","HTML");
          writeGameHtml(filename.append(".html"));
        } else {
          settings.setValue("exporttype","PDF");
          writeGamePDF(filename.append(".pdf"));
        }
      }
    }
}

void MainWindow::solveGamePressed()
{
    control->solveGame();
}

void MainWindow::hintGamePressed()
{
    control->getHint();
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
    
    exportAct = new QAction(tr("E&xport"), this);
    exportAct->setShortcut(tr("Ctrl+X"));
    connect(exportAct, SIGNAL(triggered()), this, SLOT(exportGamePressed()));

    hintAct = new QAction(tr("H&int"), this);
    hintAct->setShortcut(tr("Ctrl+I"));
    connect(hintAct, SIGNAL(triggered()), this, SLOT(hintGamePressed()));

    expertAct= new QAction(tr("&Expert"),this);
    expertAct->setCheckable(true);
    normalAct= new QAction(tr("&Normal"),this);
    normalAct->setCheckable(true);
    beginnerAct= new QAction(tr("&Beginner"),this);
    beginnerAct->setCheckable(true);
    levelGroup= new QActionGroup(this);
    levelGroup->addAction(expertAct);
    levelGroup->addAction(normalAct);
    levelGroup->addAction(beginnerAct);

    QSettings settings;
    switch(settings.value("level",2).toInt()) {
      case 1: expertAct->setChecked(true); break;
      case 2: normalAct->setChecked(true); break;
      case 3: beginnerAct->setChecked(true); break;
    }

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
   fileMenu=menuBar()->addMenu(tr("&File"));
   fileMenu->addAction(exportAct);
   fileMenu->addAction(quitAct);
   
   gameMenu=menuBar()->addMenu(tr("&Game"));
   gameMenu->addAction(newAct);
   gameMenu->addAction(enterAct);
   gameMenu->addAction(solveAct);
   gameMenu->addAction(hintAct);
   
   levelMenu=menuBar()->addMenu(tr("&Level"));
   levelMenu->addAction(expertAct);
   levelMenu->addAction(normalAct);
   levelMenu->addAction(beginnerAct);
   helpMenu=menuBar()->addMenu(tr("&Help"));
   helpMenu->addAction(helpAct);
   helpMenu->addAction(aboutAct);

}

void MainWindow::closeEvent(QCloseEvent* event)
{
  QSettings settings;
  if (expertAct->isChecked())
    settings.setValue("level",1);
  if (normalAct->isChecked())
    settings.setValue("level",2);
  if (beginnerAct->isChecked())
    settings.setValue("level",3);
  event->accept();
}

void MainWindow::helpPressed()
{
    QMessageBox::about(this,SUDOKU_VERSION,tr(
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
"see for this field.<br><b>Mac OSX hint:</b> <i>right-click = ctrl+klick</i> <p>"));
}

void MainWindow::aboutPressed()
{
    QMessageBox::about(this,SUDOKU_VERSION,tr("<p>by Andreas Bricelj"
            "<p>you may use, distribute and copy this program under the <br>GNU PUBLIC LICENSE Version 2, June 1991."
            "<p>the source code is available at <p><b>http://www.seafrog.de/sudoku</b>"
            "<p>bric@seafrog.de"));
}

