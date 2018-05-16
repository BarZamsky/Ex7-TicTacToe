//
// Created by bar on 11/05/18.
//
#include "Board.h"

Board::Board(int r)
{
    this->rows=r;
    this->game = new Node*[rows];
    for (int i = 0; i < rows; i++) {
        this->game[i] = new Node [rows];
    }
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < rows; j++) {
            game[i][j]= Node{'.'};
        }
    }
}

Board::Board(const Board& other)
{
    this->rows=other.rows;
    this->game = new Node*[rows];
    for (int i = 0; i < rows; i++) {
        this->game[i] = new Node [rows];
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<rows;j++){
            game[i][j]=other.game[i][j];
        }
    }
}

Board::~Board()
{
    for(int i=0;i<rows;i++){
        delete[] game[i];
    }
    delete[] game;
}
Node &Board::operator[](const Coordinate& cr) const{
    int a = cr.getX(), b = cr.getY();

    if (a < rows && a >= 0 && b < rows && b >= 0)
        return mat[a][b];
    else
    {
        IllegalCoordinateException ex;
        ex.setA(a);
        ex.setB(b);
        throw ex;
    }
}
/*Node& Board::operator[](list<int> list)
{
    int a = list.front(), b=list.back();
    if(a<0 || a>=rows || b<0 || b>=rows)
    {
        IllegalCoordinateException ex;
        ex.setA(a); ex.setB(b);
        throw ex;
    }
    return game[a][b];
}*/

Board& Board::operator=(const Board &b)
{
    if (this==&b)
        return *this;
    if (b.rows!=this->rows) {
        for (int i = 0; i < rows; i++)
            delete[] game[i];
        delete [] game;

        rows = b.rows;
        game = new Node*[b.rows]; // init
        for (int i = 0; i < rows; i++) {
            game[i] = new Node [rows];
        }
    }

    for (int i=0; i<rows; ++i){
        for(int j=0;j<rows;j++){
            game[i][j]=Node{b.game[i][j].getNode()};
        }
    }
    return *this;
}

Board& Board::operator=(char c)
{
    if (c=='.') {
        for (int j = 0; j < rows; ++j) {
            for (int i = 0; i < rows; ++i) {
                game[i][j] = '.';
            }
        }
    }
    else
    {
        IllegalCharException ex;
        ex.setInput(c);
        throw ex;
    }
    return *this;
}

ostream &operator<<(ostream& out, const Board& b)
{
    for (int i = 0; i < b.rows; i++)
    {
        for (int j = 0; j < b.rows; j++){
            out << b.game[i][j].getNode();
        }
        out << endl;
    }
    return out;
}

int Board::size() const
{
    return this->rows;
}