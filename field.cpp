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

#include "field.h"
#include "element.h"

QWidget* Field::buildSector(int sr, int sc) 
{
            QWidget* widget=new QWidget(this);
            QGridLayout* gridLayout=new QGridLayout(widget);
            gridLayout->setSpacing(1);
            gridLayout->setMargin(0);
            for (int r=0; r<3; r++)
                for (int c=0; c<3; c++) {
                    Element* element=new Element(widget,sr*3+r,sc*3+c);
                    gamefield[sr*3+r][sc*3+c]=element;
                    gridLayout->addWidget(element, r, c, 1, 1);
                }
            return widget;
}

Field::Field(QWidget* parent):QWidget(parent) {
    gridLayout=new QGridLayout(this);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(0);
    this->setObjectName(QString::fromUtf8("field"));
    for (int r=0; r<3 ; r++)
        for (int c=0; c<3; c++) 
            gridLayout->addWidget(buildSector(r,c),r,c,1,1);
}

Element*  Field::getElement(int r, int c) { return gamefield[r][c]; }
