#pragma once
#include <list>
#include "Piece.h"
#include <string>

class Board : public std::list<Piece>
{

	std::list<Piece>::iterator whiteKing;
	std::list<Piece>::iterator blackKing;
	int whiteKingPosiiton;
	int blackKingPosition;

public:

	Board();
	void print();
	bool isWhite(int cellNum);
	std::list<Piece>::iterator getWhiteKing()const;
	std::list<Piece>::iterator getBlackKing()const;
	int getWhiteKingPos()const;
	int getBlackKingPos()const;
	void setWhiteKing(const std::list<Piece>::iterator& whiteKing, int kingPos);
	void setBlackKing(const std::list<Piece>::iterator& blackKing, int kingPos);
	static const int DIM = 8;
	static const int BOARD_SIZE = 64;
	static const std::string BOARD_START;
	static const std::string BOARD_END;

};
 const std::string BOARD_START = "8a";
 const std::string BOARD_END = "1h";





