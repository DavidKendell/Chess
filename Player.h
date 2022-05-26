#pragma once
#include "Arbiter.h"
class Player
{
private:
	Board* board;
	bool whiteTurn = true;
public:
	Player(Board *board);
	void movePiece();
};
