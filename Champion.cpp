//
// Created by bar on 12/05/18.
//
#include "Champion.h"

const Coordinate Champion::play(const Board& board) {
    char charOfOtherPlayer = (
            myChar=='X'? 'O': 'X'
    );
    for (uint y=0; y<board.size(); ++y) {
        for (uint x=0; x<board.size(); ++x) {
            Coordinate c{x,y};
            if (board[c]==charOfOtherPlayer) {
                return c;
            }
        }
    }
    return {0,0};  // did not find an illegal square - play on the top-left
}
