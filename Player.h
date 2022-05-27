#pragma once
#include "Arbiter.h"
class Player
{
private:
	Board *board;
	bool whiteTurn = true;
public:
	Player(Board *board);
	void movePiece();
	//int calculateMove(std::string piecePosition, std::string finalPosition);
	int calculateDiff(std::string piecePosition, std::string finalPosition);
};

