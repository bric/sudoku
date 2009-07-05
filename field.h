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

#ifndef __FIELD_H__
#define __FIELD_H__
#include <QtCore>
#include <QtGui>

class Element;

class Field : public QWidget {
    Element* gamefield[9][9];
    QGridLayout *gridLayout;
    public:
        Field(QWidget* parent);
        Element*  getElement(int r, int c); 
    private:
        QWidget* buildSector(int sr, int sc);
};

#endif
