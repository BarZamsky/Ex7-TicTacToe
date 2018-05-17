//
// Created by bar on 11/05/18.
//

#include <iostream>
using namespace std;

class Node
{
    char val;

public:
    Node();
    Node(char val);
    char getNode() const;
    Node& operator=(char val);
    friend ostream& operator<< (ostream& os, Node& c);
    void setC(char c);
    operator char() const { return val; }
};

inline ostream& operator<< (ostream& os, Node& n)
{
    os << n.getNode();
    return os;
}

class Coordinate
{
    uint row,col;
public:
    Coordinate(uint x,uint y);
    void setCoordinate(Coordinate c);
    uint getRow()const {return row;}
    uint getCol()const {return col;}
    void setRow(uint x) { row=x;}
    void setCol(uint y) { col=y;}
};