#pragma once
#include <list>
#include "Piece.h"
class Board : public std::list<Piece>
{
	std::list<Piece>::iterator whiteKing;
	std::list<Piece>::iterator blackKing;
	const int DIM = 8;
	const int BOARD_SIZE = 64;
public:
	Board();
	void print();
	bool isWhite(int cellNum);

};

