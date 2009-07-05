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

#include "element.h"

Element::Element(QWidget* parent, int _r, int _c): 
    QWidget(parent), row(_r), column(_c), value(0),
    posVal(0),
    changable(false),
    wrong(false)
{
}

QFont big("Arial",24,QFont::Normal);
QFont sml("Arial",10,QFont::Normal);

void Element::paintEvent(QPaintEvent*) 
{
    QPainter painter(this);
    QPen pen(Qt::black,1);
    painter.setPen(pen);
    if (wrong)
        painter.setBrush(QBrush(Qt::red));
    else if (!changable)
        painter.setBrush(QBrush(Qt::gray));
    painter.drawRect(0,0,width()-1,height()-1);
    if (value!=0) {
        painter.setFont(big);
        painter.drawText(0,0,width()-1,height()-1,
                Qt::AlignVCenter|Qt::AlignHCenter|Qt::TextSingleLine,QString("%1").arg(value));
    } else {
        if (posVal==0) 
            return;
        painter.setFont(sml);
        painter.drawLine((width()/3),2,(width()/3),height()-3);
        painter.drawLine((2*width()/3),2,(2*width()/3),height()-3);
        painter.drawLine(2,(height()/3),width()-3,(height()/3));
        painter.drawLine(2,(2*height()/3),width()-3,(2*height()/3));
        for (int i=0; i<9; i++)
            if ((1<<i)&posVal)  
                painter.drawText(((i%3)*width())/3,((i/3)*height())/3,width()/3,height()/3,
                        Qt::AlignVCenter|Qt::AlignHCenter|Qt::TextSingleLine,QString("%1").arg(i+1));
    }
}

void Element::mousePressEvent(QMouseEvent* event)
{
   if (!changable) 
       return;
   if (value) {
       value=0;
       if (posVal==0x1ff)
           setPosVal(0);
       update();
       emit valueChanged(row,column,value);
   } else {
       int x=(event->pos().x())/(width()/3);
       int y=(event->pos().y())/(height()/3);
       int v=y*3+x;
       if (v>=9) v=8;
       if (v<0)  v=0;
       if (event->button() == Qt::LeftButton) {
           if (posVal&(1<<v))
               setValue(v+1);
           else if (posVal==0)
               setPosVal(0x1ff);
           else 
               setPosVal((posVal&0x1ff)|(1<<v));
       } else if (event->button() == Qt::RightButton) {
           if (posVal==0)
               setPosVal(0x200);
           else if (posVal&(1<<v))
               setPosVal(posVal&~(1<<v));
           else
               setPosVal(posVal|(1<<v));
       }
   }
}


int Element::getValue() 
{ 
    return value; 
}

void Element::setValue(int _value) 
{ 
    if (value==_value) return; 
    value=_value;
    emit valueChanged(row,column,value);
    if (value==0) 
        setPosVal(0x1ff);
    update();
}


void Element::setPosVal(int _posVal) 
{ 
    if (posVal==_posVal) return; 
    posVal=_posVal;
    emit posValChanged(row,column,posVal);
    update();
}

int Element::getPosVal()
{
    return posVal;
}

void Element::setWrong() 
{
  if (wrong) return;
  wrong=true;
  update();
}

void Element::setCorrect()
{
    if (!wrong) return;
    wrong=false;
    update();
}

void Element::setChangable()
{
    if (changable) return;
    changable=true;
    update();
}

void Element::setUnchangable()
{
    if (!changable) return;
    changable=false;
    update();
}
