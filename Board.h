//
// Created by bar on 11/05/18.
//

#pragma once
#include <iostream>
#include "Node.h"
#include <exception>
#include <list>
using namespace std;

class Board
{
private:
    int rows;
    Node **game;

public:
    Board(int r);
    Board(const Board& other);
    ~Board();
    Node& operator[](list<uint> list);
    Node& operator[](const Coordinate& c) const;
    Board& operator=(const Board& b);
    Board& operator=(char c);
    int size() const;
    friend ostream &operator<<(ostream &out, const Board &b);
};

class IllegalCoordinateException : public exception
{
    int a,b;
public:
    void setA(int row){
        this->a=row;
    }
    void setB(int col){
        this->b=col;
    }
    string theCoordinate ()const
    {
        return to_string(a)+","+to_string(b);
    }
};

class IllegalCharException : public exception
{
    char input;

public:
    char theChar()const
    {
        return input;
    }
    void setInput(int c){input=c;}
};