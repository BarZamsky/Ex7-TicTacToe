//
// Created by bar on 12/05/18.
//
#pragma once
#include "Board.h"
#include <string>

class Player
{

public:
    char myChar;
    Player(){}
    Player(char c){
        if (c=='O' || c== 'X')
            myChar=c;
        else{
            IllegalCharException ex;
            ex.setInput(c);
            throw ex;
        }
    }
    void setChar(char c) {myChar = c;}
    char getChar(){return myChar;}
    virtual const string name() const =0;
    virtual const Coordinate play(const Board& board)=0 ;
};
