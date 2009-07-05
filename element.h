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

#ifndef __ELEMENT__
#define __ELEMENT__
#include <QtCore>
#include <QtGui>

class Element : public QWidget {
    Q_OBJECT

        int row,column;
        int value;
        int posVal;
        bool changable;
        bool wrong;
    public:

    Element(QWidget* parent, int _row, int _column);
    int getValue();
    void setValue(int _value);
    void setWrong();
    void setCorrect();
    void setChangable();
    void setUnchangable();
    void setPosVal(int _posVal);
    int  getPosVal();
    bool isWrong() {return wrong;}

    protected:
    void paintEvent(QPaintEvent* event);
    void mousePressEvent(QMouseEvent* event);

signals:
    void valueChanged(int row, int column,int value);
    void posValChanged(int row, int column, int posVal);
};
#endif
