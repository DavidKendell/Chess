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
		return checkPawn(newPiecePos, diff, traverseDist);
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
    bool legalWhiteMove = piecePosition->isWhite && (diff == -8 ||
		!checkEmpty(newPos) && (diff == -9 || diff == -7) || 48 <= traverseDist && traverseDist <= 55 && diff == -16);
    bool legalBlackMove = !piecePosition->isWhite && (diff == 8 ||
		!checkEmpty(newPos) && (diff == 9 || diff == 7) || 8 <= traverseDist && traverseDist <= 15 && diff == 16);
    return legalBlackMove || legalWhiteMove;
}

bool checkEmpty(Board::iterator position) {
	if (position->name == '-' || position->name == '#')
		return true;
	return false;
}

bool checkCheck(Board::iterator King)

{   int directions[] {1,-1,8,-8};
    for (int i = 0; i < sizeof directions / sizeof *directions; ++i) {

    auto currentCheckLocation=King;
    for (int j = 0; j < 8; ++j) {
        std::advance(currentCheckLocation,directions[i]);
        if(!checkEmpty(currentCheckLocation))
            break;
    }

    if (reinterpret_cast<const char *>(currentCheckLocation->name) == "Queen" || reinterpret_cast<const char *>(currentCheckLocation->name) == "Rook")
        return true;
}}