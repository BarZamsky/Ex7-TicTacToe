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
    int x,y;
public:
    Coordinate(uint xVal,uint yVal);
    void setXY(uint xVal,uint yVal);
    uint getX()const {return x;}
    uint getY()const {return y;}
};