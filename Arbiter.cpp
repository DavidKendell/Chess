#include "Arbiter.h"
#include <list>
#include <cmath>


bool checkMove(Board::iterator boardBegin, Board::iterator newPiecePos,
	Board::iterator oldPicePos, int traverseDist, int diff, bool whiteTurn) {

	//if (newPiecePos->name == '\0') return false;
	//if (newPiecePos->isWhite != whiteTurn) return false;
	//else if(!checkEmpty(newPiecePos) && (newPiecePos->isWhite == oldPicePos->isWhite)) return false;
	//else if (finalPos->isWhite != whiteTurn //|| end->name != '\0' &&
		/*initpos->isWhite == end->isWhite) return false;*/

	switch (oldPicePos->name) {
	case 'R':
		return checkRook(oldPicePos, diff);
	case 'r':
		return checkRook(oldPicePos, diff);
	case 'K':
		return checkKnight(oldPicePos, diff);
	case 'k':
		return checkKnight(oldPicePos, diff);
	case 'B':
		return checkKnight(oldPicePos, diff);
	case 'b':
		return checkBishop(oldPicePos, diff);
	case 'Q':
		return checkBishop(oldPicePos, diff);
	case 'q':
		return checkQueen(oldPicePos, diff);
	case 'H':
		return checkQueen(oldPicePos, diff);
	case 'h':
		return checkKing(oldPicePos, diff);
	case 'P':
		return checkKing(oldPicePos, diff);
	case 'p':
		return checkPawn(oldPicePos, diff, traverseDist);
	default: return false;
	};
}

bool checkKing(Board::iterator piecePosition, int diff)
{
    if (abs(diff)<=9&& checkQueen(piecePosition,diff))
	return false;
}

bool checkQueen(Board::iterator piecePosition, int diff)
{   if (checkRook(piecePosition,diff)|| checkBishop(piecePosition,diff)){
    return true;

}
	return false;
}

bool checkKnight(Board::iterator newPiecePos, int diff)
{
	const int moveLeftUp = 15;
	const int moveRightUp = 17;
	const int moveLeftDown = 6;
	const int moveRightDown = 10;

	switch (abs(diff)) {
	case moveLeftUp:return true;
	case moveLeftDown:return true;
	case moveRightUp:return true;
	case moveRightDown:return true;
	default:return false;

	}

	/*Tested patterns
	1b 3c
	3c 4e
	4e 5g
	5g 6e
	6e 4f*/

	return false;
}

bool checkBishop(Board::iterator piecePosition, int diff)
{ bool toBeReturned=true;
    if (abs(diff)%9==0){
        for (int i = 0; i < abs(diff) / 9; ++i) {
            std::advance(piecePosition,9* abs(diff)/diff);
            checkEmpty(piecePosition);
        }
    }
    if(abs(diff)%7==0){
        for (int i = 0; i < abs(diff)/7; ++i) {
            std::advance(piecePosition,7*abs(diff)/diff);
            checkEmpty(piecePosition);
        }

    }
	return false;
}

bool checkRook(Board::iterator piecePosition ,int diff)
{bool toBeReturned= false;

    if (abs(diff)<8) {
        toBeReturned=true;
            for (int i = 0; i < abs(diff); ++i) {
                std::advance(piecePosition,abs(diff)/diff);
                toBeReturned = checkEmpty(piecePosition);
            }
    }


    if (diff%8 ==0) {
        toBeReturned=true;
            for (int i = 0; i < abs(diff) / 8; ++i) {
                advance(piecePosition, 8*abs(diff)/diff);
                toBeReturned = checkEmpty(piecePosition);
            }
    }
    return toBeReturned;
}

bool checkPawn(Board::iterator piecePosition, int diff, int traverseDist)
{
    auto newPos = piecePosition;
    advance(newPos, diff);
	bool white1step = diff == -8;
	bool white2step = diff == -16 && 48 <= traverseDist && traverseDist <= 55;
	bool black1step = diff == 8;
	bool black2step = 8 <= traverseDist && traverseDist <= 15 && diff == 16;
	bool whiteTake = !checkEmpty(newPos) && (diff == -9 || diff == -7);
	bool blackTake = !checkEmpty(newPos) && (diff == 9 || diff == 7);
	bool legalWhite = piecePosition->isWhite && (white1step || white2step || whiteTake);
	bool legalBlack = !piecePosition->isWhite && (black1step || black2step || blackTake);
    return legalBlack || legalWhite;
}

bool checkEmpty(Board::iterator position) {
	if (position->name == '-' || position->name == '#')
		return true;
	return false;
}