#pragma once
#include <list>
#include "Piece.h"
#include <string>

class Board : public std::list<Piece>
{
	std::list<Piece>::iterator whiteKing;
	std::list<Piece>::iterator blackKing;

public:
	Board();
	void print();
	bool isWhite(int cellNum);
	static const int DIM = 8;
	static const int BOARD_SIZE = 64;
};
