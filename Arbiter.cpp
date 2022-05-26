#include "Arbiter.h"

bool checkMove(Board::iterator begin, Board::iterator initpos, int diff, bool whiteTurn)
{
	auto end = initpos;
	std::advance(end, diff);
	if (initpos->getName() == '\0') return false;
	else if (initpos->getColor() != whiteTurn || end->getName() != '\0' &&
		initpos->getColor() == end->getColor()) return false;

	switch (initpos->getName()) {
	case 'R':
		return checkRook(initpos, diff);
	}
}

bool checkKing(Board::iterator start, int diff)
{
	return false;
}

bool checkQueen(Board::iterator start, int diff)
{
	return false;
}

bool checkKnight(Board::iterator start, int diff)
{
	return false;
}

bool checkBishop(Board::iterator start, int diff)
{
	
}

bool checkRook(Board::iterator start, int diff)
{
	return false;
}

bool checkPawn(Board::iterator start, int diff)
{
	if (diff % 8 != 0) return false;
	else if (start->isWhite) {
		if (diff == -8) {
			advance(start, diff); {
				if (start->name != '\0') return false;
			}
		}
	}
}
