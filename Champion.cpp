//
// Created by bar on 12/05/18.
//
#include "Champion.h"
const Coordinate Champion::play(const Board& board) {
    for (uint i=0; i<board.size(); ++i) {
        uint t = board.size()-1-i;
        Coordinate c{t,i};
        t = board.size()-1;
        if(i==1 && board[{0,t}] == '.'){
            c.setRow(0); c.setCol(board.size()-1);
        }
        if(board[c]=='.') {
            return c;
        }
    }
    return {0,0};
}
