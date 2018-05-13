//
// Created by bar on 11/05/18.
//
#pragma  once
#include "Board.h"
#include "Player.h"

class TicTacToe
{
    Board game;
    Player* win;
    bool checkWin(Player& p);

public:
    TicTacToe(int n);
    Board board() const;
    Player& winner() const;
    void play(Player& xPlayer, Player& oPlayer);
};
