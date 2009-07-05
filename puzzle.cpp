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

#include "puzzle.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <bitset>

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

bool Puzzle::isallowed(int i, int j, int s) {
    int si=3*(i/3);
    int sj=3*(j/3);
    for (int t=0; t<9; t++) {
        if (field[i][t]==s) return false;
        if (field[t][j]==s) return false;
        if (field[si+t/3][sj+t%3]==s) return false;
    }
    return true;
}

int Puzzle::solve(bool countOnly,int start) {
     for (int l=start; l<81; l++) {
	 int i=l%9;
	 int j=l/9; 
         if (field[i][j]==0) {
             int solcount=0;
             int solution=0;
             for (int s=1;s<10;s++) {
                 if (isallowed(i,j,s)) {
                     field[i][j]=s;
                     int numsolutions=solve(countOnly,l+1);
                     if (numsolutions==1)
                         solution=s;
                     solcount+=numsolutions;
                     field[i][j]=0;
		     if (solcount>1) 
			     return solcount;
                 }
             }
             if (solcount==1 && !countOnly)
                 field[i][j]=solution;
             return solcount;
         }
     }
  return 1;
}

void Puzzle::generate(int nr) 
{
    typedef bitset<9> BS;
    BS rows[9], cols[9], quad[9];
    srand(nr);

start:    
    //reset field
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
    // now reduce the field to get the puzzle
    int level=7;
    for(;;) {
        int i=rand()%9;
        int j=rand()%9; 
        int s=field[i][j];
        if (s!=0) {
            field[i][j]=0;
            int solutions=solve(true);
            if (solutions>1) {
                field[i][j]=s;
                if (level--<0)
                  break;
            } else if (solutions==0) {
                // error treatment missing, at first we simply restart
                goto start;
            } 
        }
    }
}

