//
// Created by bar on 12/05/18.
//
#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
    for (uint x=0; x<board.size(); ++x) {
        uint t = board.size()-1-x;
        uint s = board.size()-1;
        Coordinate c{t,x};
        if(x==1 && board[{0,s}] == '.')
            c.setRow(0); c.setCol(s);
        if(board[c]=='.') {
            return c;
        }

    }
    return {0,0};

}
