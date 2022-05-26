#include "Arbiter.h"

bool checkMove(Board::iterator start, int diff, bool whiteTurn)
{
	auto end = start;
	std::advance(end, diff);
	if (start->getName() == '\0') return false;
	else if (start->getColor() != whiteTurn ||end->getName() != '\0' &&
		start->getColor() == end->getColor()) return false;

	switch (start->getName()) {
	case 'R':
		return checkRook(diff);
	}
}

bool checkKing(int diff)
{
	return false;
}

bool checkQueen(int diff)
{
	return false;
}

bool checkKnight(int diff)
{
	return false;
}

bool checkBishop(int diff)
{
	return false;
}

bool checkRook(int diff)
{ if (diff ==1||diff==-1||diff==8||diff==-8)
    return true;
	return false;
}

bool checkPawn(int diff)
{
	return false;
}
