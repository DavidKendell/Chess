#pragma once
#include <list>
#include "Piece.h"
#include <string>

class Board : public std::list<Piece>
{
public:

	Board();
	void print();
	bool isWhite(int cellNum);
	static const int DIM = 8;
	static const int BOARD_SIZE = 64;
	static const std::string BOARD_START;
	static const std::string BOARD_END;
	static std::list<Piece>::iterator whiteKing;
	static std::list<Piece>::iterator blackKing;
};
 const std::string BOARD_START = "8a";
 const std::string BOARD_END = "1h";





