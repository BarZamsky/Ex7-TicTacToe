//
// Created by bar on 11/05/18.
//
#pragma once
#include "Board.h"
#include "Player.h"

class TicTacToe{
public:
    Board game;
    int _size;
    Player* champion; // the winner

public:
    TicTacToe(int n);
    Board board() const;
    Player& winner() const;
    void play(Player& xPlayer, Player& oPlayer);
    bool checkWinner(char c);

};
