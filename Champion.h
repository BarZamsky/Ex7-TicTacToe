//
// Created by bar on 11/05/18.
//
#pragma  once
#include "Player.h"

class Champion : public Player
{
public:
    const Coordinate play(const Board& board) override ;
    const string name() const override {
        return "Bar Zamsky & Shahar Botesazan";
    };
};
