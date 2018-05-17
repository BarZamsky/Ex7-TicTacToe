//
// Created by bar on 12/05/18.
//

#include "TicTacToe.h"
#include <string>

TicTacToe::TicTacToe(int n):game(n){
    _size=n;
}

Board TicTacToe::board() const
{
    return game;
}
Player& TicTacToe::winner() const
{
    return *champion;
}

void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    this->game ='.'; // initial empty board
    int s = _size*_size;
    int count = 0;
    xPlayer.setChar('X');
    oPlayer.setChar('O');
    Coordinate c(0,0);
    while(count < s){
        count++;
        try{
            c.setCoordinate(xPlayer.play(game));
            if(game[c]=='.')
                game[c] = xPlayer.getChar();
            else{
                champion = &oPlayer; return;
            }
        }
        catch(const string& msg) {
            champion = &oPlayer; return;
        }

        if(checkWinner('X')) {
            champion = &xPlayer; return;
        }
        count++;
        if(count < s){
            try{
                c.setCoordinate(oPlayer.play(game));
                if(game[c]=='.')
                    game[c] = oPlayer.getChar();
                else{
                    champion = &xPlayer; return;
                }
            }
            catch(const string& msg) {
                champion = &xPlayer; return;
            }

            if(checkWinner('O')) {
                champion= &oPlayer; return;
            }
        }
    }
    champion = &oPlayer;
}
bool TicTacToe::checkWinner(char c)
{
    bool winning = true;

    for(uint i = 0; i< _size ; i++)
    {
        winning = true;
        for(uint j = 0; j<_size ; j++)
        {
            if(game[{i,j}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;

        winning = true;
        for(uint j = 0; j<_size ; j++)
        {
            if(game[{j,i}] != c){
                winning = false;
                break;
            }
        }
        if(winning)
            return true;
    }

    winning = true;
    for(uint i = 0; i<_size ; i++)
    {
        if(game[{i,i}] != c){
            winning = false;
            break;
        }
    }
    if(winning)
        return true;
    winning = true;
    for(uint i = 0; i<_size ; i++)
    {
        if(game[{_size-i-1,i}] != c){
            winning = false;
            break;
        }
    }
    return winning;
}