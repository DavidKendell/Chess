#include "Arbiter.h"
#include <list>
#include <iterator>
#include <math.h>


bool checkMove(Board::iterator boardBegin, Board::iterator newPiecePos,
	Board::iterator oldPicePos, int traverseDist, int diff, bool whiteTurn) {

	//Board::iterator startPos = newPiecePos;
	
	//std::advance(startPos, abs(diff));
	//if (newPiecePos->name == '\0') return false;
	//else if (newPiecePos->isWhite != whiteTurn || end->name != '\0' &&
	 //checkLine(newPiecePos) && (newPiecePos->isWhite == oldPicePos->isWhite)) return false;
	//else if (finalPos->isWhite != whiteTurn //|| end->name != '\0' &&
		/*initpos->isWhite == end->isWhite) return false;*/

	switch (oldPicePos->name) {
	case 'R':
		return checkRook(newPiecePos, diff);
	case 'r':
		return checkRook(newPiecePos, diff);
	case 'K':
		return checkKnight(newPiecePos, diff);
	case 'k':
		return checkKnight(newPiecePos, diff);
	case 'B':
		return checkKnight(newPiecePos, diff);
	case 'b':
		return checkBishop(newPiecePos, diff);
	case 'Q':
		return checkBishop(newPiecePos, diff);
	case 'q':
		return checkQueen(newPiecePos, diff);
	case 'H':
		return checkQueen(newPiecePos, diff);
	case 'h':
		return checkKing(newPiecePos, diff);
	case 'P':
		return checkKing(newPiecePos, diff);
	case 'p':
		return checkPawn(newPiecePos, diff);
	default: return false;
	};
}


bool checkKing(Board::iterator start, int diff)
{
	return false;
}

bool checkQueen(Board::iterator start, int diff)
{
	return false;
}

bool checkKnight(Board::iterator newPiecePos, int diff)
{
	const int moveLeft = 15;
	const int moveRight = 17;

	if (diff == moveLeft || diff == (-moveLeft)
		|| diff == moveRight || diff == (-moveRight)) {
		return true;

	}
	return false;
}

bool checkBishop(Board::iterator start, int diff)
{
	return false;
}
bool checkLine(Board::iterator position) {
	if (position->name == '-' || position->name == '#')
		return true;
	return false;
}
bool checkRook(Board::iterator start, int diff)
{
	bool toBeReturned = false;
	if (diff < 8 && diff>0)
		for (int i = 0; i < diff; ++i) {
			start++;
			toBeReturned = checkLine(start);
		}
	if (diff > (-8) && diff < 0)
		for (int i = 0; i > diff; --i) {
			start--;
			toBeReturned = checkLine(start);

		}
	if (diff % 8 == 0)
		if (diff > 0)
			for (int i = 0; i < diff / 8; ++i) {
				advance(start, 8);
				toBeReturned = checkLine(start);

			}
	if (diff < 0)
		for (int i = 0; i > diff / 8; ++i) {
			advance(start, -8);
			toBeReturned = checkLine(start);

		}


	return toBeReturned;
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
	return true;
}


