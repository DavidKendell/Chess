#include "Arbiter.h"
#include <list>

#include <cmath>

bool checkMove(Board::iterator begin, Board::iterator initpos, int diff, bool whiteTurn)
{
	auto end = initpos;
	std::advance(end, diff);
	if (checkEmpty(initpos)) return false;
	else if (initpos->isWhite != whiteTurn || end->name != '\0' &&
		initpos->isWhite == end->isWhite) return false;

	switch (initpos->name) {
	    case 'R':
		    return checkRook(initpos, diff);
        case 'K':
            return checkKnight(initpos,diff);
        case 'B':
            return checkBishop(initpos,diff);
        case 'Q':
            return checkQueen(initpos,diff);
        case 'H':
            return checkKing(initpos,diff);
        case 'P':
            return checkPawn(initpos,diff);

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

bool checkKnight(Board::iterator piecePosition, int diff)
{
		const int moveLeft = 15;
		const int moveRight = 17;

		if (diff ==  moveLeft || diff == (-moveLeft)
			|| diff == moveRight || diff == (-moveRight)){

			std::advance(piecePosition, diff);

			return true;

	}
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
    if(abs(diff)==7){
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

bool checkPawn(Board::iterator piecePosition, int diff)
{
	if (diff % 8 != 0) return false;
	else if (piecePosition->isWhite) {
		if (diff == -8) {
			advance(piecePosition, diff); {
				if (!checkEmpty(piecePosition)) return false;
			}
		}
	}
	return true;
}
bool checkEmpty(Board::iterator position){
    if(position->name =='-'||position->name=='#')
        return true;
    return false;
}