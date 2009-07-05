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

#ifndef __PUZZLE_H__
#define __PUZZLE_H__

class Puzzle {
    unsigned char field[9][9];

    bool isallowed(int i, int j, int s);
    public:
    Puzzle();
    int solve(bool countOnly=false, int start=0);
    void generate(int nr); 
    int get(int row, int column);
    void set(int row, int column, int value);
};

#endif
