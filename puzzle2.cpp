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

#include "puzzle.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bitset>
#include <vector>
#include <QCoreApplication>

using namespace std;

Puzzle::Puzzle() {
    for (int j=0; j<9; j++)
       for (int i=0; i<9; i++)
           field[i][j]=0;
}

int Puzzle::get(int row, int column) {
  return field[row][column];
}

void Puzzle::set(int row, int column, int value) {
  field[row][column]=value;
}

int Puzzle::getChoices(int i, int j) {
    int si=3*(i/3);
    int sj=3*(j/3);
    int v;
    int res=0x1ff;
    for (int t=0; t<9; t++) {
        if ((v=field[i][t])) res&=~(1<<(v-1));
        if ((v=field[t][j])) res&=~(1<<(v-1));
        if ((v=field[si+t/3][sj+t%3])) res&=~(1<<(v-1));
        if (!res) break;
    }
    return res;
}

int Puzzle::solve(bool countOnly,int start) {
  if (start<81) {
    int i=start%9;
    int j=start/9; 
    if (field[i][j]==0) {
      int solcount=0;
      int solution=0;
      int choices=getChoices(i,j);
      for (int s=1; (s<10) && (choices!=0); s++) 
        if (choices&(1<<(s-1))) {
          choices&=~(1<<(s-1)); 
          field[i][j]=s;
          int numsolutions=solve(true,start+1);
          if (numsolutions==1)
            solution=s;
          solcount+=numsolutions;
          field[i][j]=0;
          if (solcount>1) {
            return solcount;
          }
        }
      if ((solcount==1) && !countOnly) {
        field[i][j]=solution;
        solve(false,start+1);
      }
      return solcount;
    } else {
      return solve(countOnly,start+1);
    }
  }
  return 1;
}

void Puzzle::generate(int nr) 
{
	nr=13946;
    typedef bitset<9> BS;
    BS rows[9], cols[9], quad[9];
    srand(nr);

start:    
    qDebug("start generation");
    //reset field
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    for (int j=0; j<9; j++)
       for (int i=0; i<9; i++) {
           field[i][j]=0;
           cols[i].reset();
           rows[j].reset();
           quad[i/3+3*(j/3)].reset();
       }
    //try to generate a valid solution
    for (int j=0; j<9; j++)
        for (int i=0; i<9; i++) {
            BS rest=~(cols[i] | rows[j] | quad[i/3+3*(j/3)]);
            int c=rest.count();
            if (c==0) {
                // this does not lead to something solvable, restart
               goto start;
            }       
            int cnt= rand()%c +1;
            int idx=0;
            while (cnt>0 && idx<9) {
                if (rest[idx]) {
                    cnt--;
                    if (cnt==0) {
                        cols[i][idx]=1;
                        rows[j][idx]=1;
                        quad[i/3+3*(j/3)][idx]=1;
                        break;
                    } 
                }
                idx++;
            }
           field[i][j]=++idx;

        }
    QCoreApplication::processEvents(QEventLoop::ExcludeUserInputEvents);
    vector<int> rest;
    for (int i=0; i<9; i++)
      for (int j=0; j<9; j++)
         if (field[i][j])
           rest.push_back((i<<8)+j);
    while (rest.size()>0) {
       int r=rand()%rest.size();
       int i=rest.at(r)>>8;
       int j=rest.at(r)&0xff;
       rest.erase(rest.begin()+r);
       int s=field[i][j];
    qDebug("reduction of (%i,%i) = %i",i,j,s);
       field[i][j]=0;
       int solutions=solve(true);
       if (solutions>1) 
         field[i][j]=s;
    }
}

