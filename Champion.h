//
// Created by bar on 11/05/18.
//
#include "Player.h"

class Champion : public Player
{
public:
    const string name() const override {return "Bar & Shahar";};
    const Coordinate play(const Board& board) override ;
};
