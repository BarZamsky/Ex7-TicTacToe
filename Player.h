//
// Created by bar on 12/05/18.
//

#include "Board.h"
#include <string>

class Player
{

public:
    char myChar;
    void setChar(char c) {myChar = c;}
    char getChar(){return myChar;}
    virtual const string name() const =0;
    virtual const Coordinate play(const Board& board)=0 ;
};
