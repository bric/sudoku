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

#ifndef SUDOKU_H
#define SUDOKU_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget_3;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout1;
    QFrame *frame_8_3;
    QFrame *frame_6_3;
    QFrame *frame_12;
    QFrame *frame_7_3;
    QFrame *frame_9_3;
    QFrame *frame_4_3;
    QFrame *frame_10_3;
    QFrame *frame_5_3;
    QFrame *frame_3_3;
    QGridLayout *gridLayout2;
    QFrame *frame_8_2_2_2_2_2_2_2_2_2;
    QFrame *frame_6_2_2_2_2_2_2_2_2_2;
    QFrame *frame_11_2_2_2_2_2_2_2_2;
    QFrame *frame_7_2_2_2_2_2_2_2_2_2;
    QFrame *frame_9_2_2_2_2_2_2_2_2_2;
    QFrame *frame_4_2_2_2_2_2_2_2_2_2;
    QFrame *frame_10_2_2_2_2_2_2_2_2_2;
    QFrame *frame_5_2_2_2_2_2_2_2_2_2;
    QFrame *frame_3_2_2_2_2_2_2_2_2_2;
    QGridLayout *gridLayout3;
    QFrame *frame_8_2_2_3;
    QFrame *frame_6_2_2_3;
    QFrame *frame_11_2_3;
    QFrame *frame_7_2_2_3;
    QFrame *frame_9_2_2_3;
    QFrame *frame_4_2_2_3;
    QFrame *frame_10_2_2_3;
    QFrame *frame_5_2_2_3;
    QFrame *frame_3_2_2_3;
    QGridLayout *gridLayout4;
    QFrame *frame_8_2_2_2_3;
    QFrame *frame_6_2_2_2_3;
    QFrame *frame_11_2_2_3;
    QFrame *frame_7_2_2_2_3;
    QFrame *frame_9_2_2_2_3;
    QFrame *frame_4_2_2_2_3;
    QFrame *frame_10_2_2_2_3;
    QFrame *frame_5_2_2_2_3;
    QFrame *frame_3_2_2_2_3;
    QGridLayout *gridLayout5;
    QFrame *frame_8_2_2_2_2_2_2_3;
    QFrame *frame_6_2_2_2_2_2_2_3;
    QFrame *frame_11_2_2_2_2_2_3;
    QFrame *frame_7_2_2_2_2_2_2_3;
    QFrame *frame_9_2_2_2_2_2_2_3;
    QFrame *frame_4_2_2_2_2_2_2_3;
    QFrame *frame_10_2_2_2_2_2_2_3;
    QFrame *frame_5_2_2_2_2_2_2_3;
    QFrame *frame_3_2_2_2_2_2_2_3;
    QGridLayout *gridLayout6;
    QFrame *frame_8_2_2_2_2_2_2_2_3;
    QFrame *frame_6_2_2_2_2_2_2_2_3;
    QFrame *frame_11_2_2_2_2_2_2_3;
    QFrame *frame_7_2_2_2_2_2_2_2_3;
    QFrame *frame_9_2_2_2_2_2_2_2_3;
    QFrame *frame_4_2_2_2_2_2_2_2_3;
    QFrame *frame_10_2_2_2_2_2_2_2_3;
    QFrame *frame_5_2_2_2_2_2_2_2_3;
    QFrame *frame_3_2_2_2_2_2_2_2_3;
    QGridLayout *gridLayout7;
    QFrame *frame_8_2_2_2_2_2_3;
    QFrame *frame_6_2_2_2_2_2_3;
    QFrame *frame_11_2_2_2_2_3;
    QFrame *frame_7_2_2_2_2_2_3;
    QFrame *frame_9_2_2_2_2_2_3;
    QFrame *frame_4_2_2_2_2_2_3;
    QFrame *frame_10_2_2_2_2_2_3;
    QFrame *frame_5_2_2_2_2_2_3;
    QFrame *frame_3_2_2_2_2_2_3;
    QGridLayout *gridLayout8;
    QFrame *frame_8_2_2_2_2_3;
    QFrame *frame_6_2_2_2_2_3;
    QFrame *frame_11_2_2_2_3;
    QFrame *frame_7_2_2_2_2_3;
    QFrame *frame_9_2_2_2_2_3;
    QFrame *frame_4_2_2_2_2_3;
    QFrame *frame_10_2_2_2_2_3;
    QFrame *frame_5_2_2_2_2_3;
    QFrame *frame_3_2_2_2_2_3;
    QGridLayout *gridLayout9;
    QFrame *frame_8_2_3;
    QFrame *frame_6_2_3;
    QFrame *frame_11_3;
    QFrame *frame_7_2_3;
    QFrame *frame_9_2_3;
    QFrame *frame_4_2_3;
    QFrame *frame_10_2_3;
    QFrame *frame_5_2_3;
    QFrame *frame_3_2_3;

    void setupUi(QMainWindow *MainWindow)
    {
    MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(QSize(800, 600).expandedTo(MainWindow->minimumSizeHint()));
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    layoutWidget_3 = new QWidget(centralWidget);
    layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
    layoutWidget_3->setGeometry(QRect(20, 20, 441, 431));
    gridLayout = new QGridLayout(layoutWidget_3);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    gridLayout1 = new QGridLayout();
    gridLayout1->setSpacing(1);
    gridLayout1->setMargin(0);
    gridLayout1->setObjectName(QString::fromUtf8("gridLayout1"));
    frame_8_3 = new QFrame(layoutWidget_3);
    frame_8_3->setObjectName(QString::fromUtf8("frame_8_3"));
    frame_8_3->setFrameShape(QFrame::StyledPanel);
    frame_8_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_8_3, 2, 0, 1, 1);

    frame_6_3 = new QFrame(layoutWidget_3);
    frame_6_3->setObjectName(QString::fromUtf8("frame_6_3"));
    frame_6_3->setFrameShape(QFrame::StyledPanel);
    frame_6_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_6_3, 1, 1, 1, 1);

    frame_12 = new QFrame(layoutWidget_3);
    frame_12->setObjectName(QString::fromUtf8("frame_12"));
    frame_12->setFrameShape(QFrame::StyledPanel);
    frame_12->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_12, 0, 0, 1, 1);

    frame_7_3 = new QFrame(layoutWidget_3);
    frame_7_3->setObjectName(QString::fromUtf8("frame_7_3"));
    frame_7_3->setFrameShape(QFrame::StyledPanel);
    frame_7_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_7_3, 1, 2, 1, 1);

    frame_9_3 = new QFrame(layoutWidget_3);
    frame_9_3->setObjectName(QString::fromUtf8("frame_9_3"));
    frame_9_3->setFrameShape(QFrame::StyledPanel);
    frame_9_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_9_3, 2, 1, 1, 1);

    frame_4_3 = new QFrame(layoutWidget_3);
    frame_4_3->setObjectName(QString::fromUtf8("frame_4_3"));
    frame_4_3->setFrameShape(QFrame::StyledPanel);
    frame_4_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_4_3, 0, 2, 1, 1);

    frame_10_3 = new QFrame(layoutWidget_3);
    frame_10_3->setObjectName(QString::fromUtf8("frame_10_3"));
    frame_10_3->setFrameShape(QFrame::StyledPanel);
    frame_10_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_10_3, 2, 2, 1, 1);

    frame_5_3 = new QFrame(layoutWidget_3);
    frame_5_3->setObjectName(QString::fromUtf8("frame_5_3"));
    frame_5_3->setFrameShape(QFrame::StyledPanel);
    frame_5_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_5_3, 1, 0, 1, 1);

    frame_3_3 = new QFrame(layoutWidget_3);
    frame_3_3->setObjectName(QString::fromUtf8("frame_3_3"));
    frame_3_3->setFrameShape(QFrame::StyledPanel);
    frame_3_3->setFrameShadow(QFrame::Raised);

    gridLayout1->addWidget(frame_3_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout1, 0, 0, 1, 1);

    gridLayout2 = new QGridLayout();
    gridLayout2->setSpacing(1);
    gridLayout2->setMargin(0);
    gridLayout2->setObjectName(QString::fromUtf8("gridLayout2"));
    frame_8_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_8_2_2_2_2_2_2_2_2_2"));
    frame_8_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_8_2_2_2_2_2_2_2_2_2, 2, 0, 1, 1);

    frame_6_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_6_2_2_2_2_2_2_2_2_2"));
    frame_6_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_6_2_2_2_2_2_2_2_2_2, 1, 1, 1, 1);

    frame_11_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_11_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_11_2_2_2_2_2_2_2_2"));
    frame_11_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_11_2_2_2_2_2_2_2_2, 0, 0, 1, 1);

    frame_7_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_7_2_2_2_2_2_2_2_2_2"));
    frame_7_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_7_2_2_2_2_2_2_2_2_2, 1, 2, 1, 1);

    frame_9_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_9_2_2_2_2_2_2_2_2_2"));
    frame_9_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_9_2_2_2_2_2_2_2_2_2, 2, 1, 1, 1);

    frame_4_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_4_2_2_2_2_2_2_2_2_2"));
    frame_4_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_4_2_2_2_2_2_2_2_2_2, 0, 2, 1, 1);

    frame_10_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_10_2_2_2_2_2_2_2_2_2"));
    frame_10_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_10_2_2_2_2_2_2_2_2_2, 2, 2, 1, 1);

    frame_5_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_5_2_2_2_2_2_2_2_2_2"));
    frame_5_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_5_2_2_2_2_2_2_2_2_2, 1, 0, 1, 1);

    frame_3_2_2_2_2_2_2_2_2_2 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_2_2_2_2_2_2->setObjectName(QString::fromUtf8("frame_3_2_2_2_2_2_2_2_2_2"));
    frame_3_2_2_2_2_2_2_2_2_2->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_2_2_2_2_2_2->setFrameShadow(QFrame::Raised);

    gridLayout2->addWidget(frame_3_2_2_2_2_2_2_2_2_2, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout2, 2, 2, 1, 1);

    gridLayout3 = new QGridLayout();
    gridLayout3->setSpacing(1);
    gridLayout3->setMargin(0);
    gridLayout3->setObjectName(QString::fromUtf8("gridLayout3"));
    frame_8_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_3"));
    frame_8_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_8_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_3"));
    frame_6_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_6_2_2_3, 1, 1, 1, 1);

    frame_11_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_3->setObjectName(QString::fromUtf8("frame_11_2_3"));
    frame_11_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_11_2_3, 0, 0, 1, 1);

    frame_7_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_3"));
    frame_7_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_7_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_3"));
    frame_9_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_9_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_3"));
    frame_4_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_4_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_3"));
    frame_10_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_10_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_3"));
    frame_5_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_5_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_3"));
    frame_3_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout3->addWidget(frame_3_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout3, 0, 2, 1, 1);

    gridLayout4 = new QGridLayout();
    gridLayout4->setSpacing(1);
    gridLayout4->setMargin(0);
    gridLayout4->setObjectName(QString::fromUtf8("gridLayout4"));
    frame_8_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_2_3"));
    frame_8_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_8_2_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_2_3"));
    frame_6_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_6_2_2_2_3, 1, 1, 1, 1);

    frame_11_2_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_2_3->setObjectName(QString::fromUtf8("frame_11_2_2_3"));
    frame_11_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_11_2_2_3, 0, 0, 1, 1);

    frame_7_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_2_3"));
    frame_7_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_7_2_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_2_3"));
    frame_9_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_9_2_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_2_3"));
    frame_4_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_4_2_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_2_3"));
    frame_10_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_10_2_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_2_3"));
    frame_5_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_5_2_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_2_3"));
    frame_3_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout4->addWidget(frame_3_2_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout4, 1, 0, 1, 1);

    gridLayout5 = new QGridLayout();
    gridLayout5->setSpacing(1);
    gridLayout5->setMargin(0);
    gridLayout5->setObjectName(QString::fromUtf8("gridLayout5"));
    frame_8_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_2_2_2_2_3"));
    frame_8_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_8_2_2_2_2_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_2_2_2_2_3"));
    frame_6_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_6_2_2_2_2_2_2_3, 1, 1, 1, 1);

    frame_11_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_11_2_2_2_2_2_3"));
    frame_11_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_11_2_2_2_2_2_3, 0, 0, 1, 1);

    frame_7_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_2_2_2_2_3"));
    frame_7_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_7_2_2_2_2_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_2_2_2_2_3"));
    frame_9_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_9_2_2_2_2_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_2_2_2_2_3"));
    frame_4_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_4_2_2_2_2_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_2_2_2_2_3"));
    frame_10_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_10_2_2_2_2_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_2_2_2_2_3"));
    frame_5_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_5_2_2_2_2_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_2_2_2_2_3"));
    frame_3_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout5->addWidget(frame_3_2_2_2_2_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout5, 2, 0, 1, 1);

    gridLayout6 = new QGridLayout();
    gridLayout6->setSpacing(1);
    gridLayout6->setMargin(0);
    gridLayout6->setObjectName(QString::fromUtf8("gridLayout6"));
    frame_8_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_2_2_2_2_2_3"));
    frame_8_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_8_2_2_2_2_2_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_2_2_2_2_2_3"));
    frame_6_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_6_2_2_2_2_2_2_2_3, 1, 1, 1, 1);

    frame_11_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_11_2_2_2_2_2_2_3"));
    frame_11_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_11_2_2_2_2_2_2_3, 0, 0, 1, 1);

    frame_7_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_2_2_2_2_2_3"));
    frame_7_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_7_2_2_2_2_2_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_2_2_2_2_2_3"));
    frame_9_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_9_2_2_2_2_2_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_2_2_2_2_2_3"));
    frame_4_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_4_2_2_2_2_2_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_2_2_2_2_2_3"));
    frame_10_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_10_2_2_2_2_2_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_2_2_2_2_2_3"));
    frame_5_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_5_2_2_2_2_2_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_2_2_2_2_2_3"));
    frame_3_2_2_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout6->addWidget(frame_3_2_2_2_2_2_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout6, 2, 1, 1, 1);

    gridLayout7 = new QGridLayout();
    gridLayout7->setSpacing(1);
    gridLayout7->setMargin(0);
    gridLayout7->setObjectName(QString::fromUtf8("gridLayout7"));
    frame_8_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_2_2_2_3"));
    frame_8_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_8_2_2_2_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_2_2_2_3"));
    frame_6_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_6_2_2_2_2_2_3, 1, 1, 1, 1);

    frame_11_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_11_2_2_2_2_3"));
    frame_11_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_11_2_2_2_2_3, 0, 0, 1, 1);

    frame_7_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_2_2_2_3"));
    frame_7_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_7_2_2_2_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_2_2_2_3"));
    frame_9_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_9_2_2_2_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_2_2_2_3"));
    frame_4_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_4_2_2_2_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_2_2_2_3"));
    frame_10_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_10_2_2_2_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_2_2_2_3"));
    frame_5_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_5_2_2_2_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_2_2_2_3"));
    frame_3_2_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout7->addWidget(frame_3_2_2_2_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout7, 1, 2, 1, 1);

    gridLayout8 = new QGridLayout();
    gridLayout8->setSpacing(1);
    gridLayout8->setMargin(0);
    gridLayout8->setObjectName(QString::fromUtf8("gridLayout8"));
    frame_8_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_8_2_2_2_2_3"));
    frame_8_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_8_2_2_2_2_3, 2, 0, 1, 1);

    frame_6_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_6_2_2_2_2_3"));
    frame_6_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_6_2_2_2_2_3, 1, 1, 1, 1);

    frame_11_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_11_2_2_2_3->setObjectName(QString::fromUtf8("frame_11_2_2_2_3"));
    frame_11_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_11_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_11_2_2_2_3, 0, 0, 1, 1);

    frame_7_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_7_2_2_2_2_3"));
    frame_7_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_7_2_2_2_2_3, 1, 2, 1, 1);

    frame_9_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_9_2_2_2_2_3"));
    frame_9_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_9_2_2_2_2_3, 2, 1, 1, 1);

    frame_4_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_4_2_2_2_2_3"));
    frame_4_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_4_2_2_2_2_3, 0, 2, 1, 1);

    frame_10_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_10_2_2_2_2_3"));
    frame_10_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_10_2_2_2_2_3, 2, 2, 1, 1);

    frame_5_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_5_2_2_2_2_3"));
    frame_5_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_5_2_2_2_2_3, 1, 0, 1, 1);

    frame_3_2_2_2_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_2_2_2_3->setObjectName(QString::fromUtf8("frame_3_2_2_2_2_3"));
    frame_3_2_2_2_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_2_2_2_3->setFrameShadow(QFrame::Raised);

    gridLayout8->addWidget(frame_3_2_2_2_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout8, 1, 1, 1, 1);

    gridLayout9 = new QGridLayout();
    gridLayout9->setSpacing(1);
    gridLayout9->setMargin(0);
    gridLayout9->setObjectName(QString::fromUtf8("gridLayout9"));
    frame_8_2_3 = new QFrame(layoutWidget_3);
    frame_8_2_3->setObjectName(QString::fromUtf8("frame_8_2_3"));
    frame_8_2_3->setFrameShape(QFrame::StyledPanel);
    frame_8_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_8_2_3, 2, 0, 1, 1);

    frame_6_2_3 = new QFrame(layoutWidget_3);
    frame_6_2_3->setObjectName(QString::fromUtf8("frame_6_2_3"));
    frame_6_2_3->setFrameShape(QFrame::StyledPanel);
    frame_6_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_6_2_3, 1, 1, 1, 1);

    frame_11_3 = new QFrame(layoutWidget_3);
    frame_11_3->setObjectName(QString::fromUtf8("frame_11_3"));
    frame_11_3->setFrameShape(QFrame::StyledPanel);
    frame_11_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_11_3, 0, 0, 1, 1);

    frame_7_2_3 = new QFrame(layoutWidget_3);
    frame_7_2_3->setObjectName(QString::fromUtf8("frame_7_2_3"));
    frame_7_2_3->setFrameShape(QFrame::StyledPanel);
    frame_7_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_7_2_3, 1, 2, 1, 1);

    frame_9_2_3 = new QFrame(layoutWidget_3);
    frame_9_2_3->setObjectName(QString::fromUtf8("frame_9_2_3"));
    frame_9_2_3->setFrameShape(QFrame::StyledPanel);
    frame_9_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_9_2_3, 2, 1, 1, 1);

    frame_4_2_3 = new QFrame(layoutWidget_3);
    frame_4_2_3->setObjectName(QString::fromUtf8("frame_4_2_3"));
    frame_4_2_3->setFrameShape(QFrame::StyledPanel);
    frame_4_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_4_2_3, 0, 2, 1, 1);

    frame_10_2_3 = new QFrame(layoutWidget_3);
    frame_10_2_3->setObjectName(QString::fromUtf8("frame_10_2_3"));
    frame_10_2_3->setFrameShape(QFrame::StyledPanel);
    frame_10_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_10_2_3, 2, 2, 1, 1);

    frame_5_2_3 = new QFrame(layoutWidget_3);
    frame_5_2_3->setObjectName(QString::fromUtf8("frame_5_2_3"));
    frame_5_2_3->setFrameShape(QFrame::StyledPanel);
    frame_5_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_5_2_3, 1, 0, 1, 1);

    frame_3_2_3 = new QFrame(layoutWidget_3);
    frame_3_2_3->setObjectName(QString::fromUtf8("frame_3_2_3"));
    frame_3_2_3->setFrameShape(QFrame::StyledPanel);
    frame_3_2_3->setFrameShadow(QFrame::Raised);

    gridLayout9->addWidget(frame_3_2_3, 0, 1, 1, 1);


    gridLayout->addLayout(gridLayout9, 0, 1, 1, 1);

    MainWindow->setCentralWidget(centralWidget);
    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow"));
    Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // SUDOKU_H
