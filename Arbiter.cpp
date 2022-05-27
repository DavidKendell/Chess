#include "Arbiter.h"
#include <list>
#include <iterator>
#include <math.h>

bool checkMove(Board::iterator begin, Board::iterator initpos, int diff, bool whiteTurn)
{
	auto end = initpos;
	std::advance(end, diff);
	if (initpos->name == '\0') return false;
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

bool checkKing(Board::iterator start, int diff)
{
    if (abs(diff)<=9&& checkQueen(start,diff))
	return false;
}

bool checkQueen(Board::iterator start, int diff)
{   if (checkRook(start,diff)|| checkBishop(start,diff)){
    return true;

}
	return false;
}

bool checkKnight(Board::iterator start, int diff)
{
		const int moveLeft = 15;
		const int moveRight = 17;

		if (diff ==  moveLeft || diff == (-moveLeft)
			|| diff == moveRight || diff == (-moveRight)){

			std::advance(start, diff);

			return true;

	}
	return false;
}

bool checkBishop(Board::iterator start, int diff)
{
	return false;
}
bool checkLine(Board::iterator position){
    if(position->name =='-'||position->name=='#')
        return true;
    return false;
}
bool checkRook(Board::iterator start ,int diff)
{bool toBeReturned= false;
    if (diff<8&&diff>0)
        for (int i = 0; i < diff; ++i) {
            start++;
            toBeReturned=checkLine(start);
        }
    if(diff> (-8)&&diff<0)
        for (int i = 0; i > diff; --i) {
            start--;
            toBeReturned =checkLine(start);

        }
    if (diff%8 ==0) {
        if (diff > 0)
            for (int i = 0; i < diff / 8; ++i) {
                advance(start, 8);
                toBeReturned = checkLine(start);

            }
        if (diff < 0)
            for (int i = 0; i > diff / 8; --i) {
                advance(start, -8);
                toBeReturned = checkLine(start);

            }
    }


    return toBeReturned;
}

bool checkPawn(Board::iterator start, int diff)
{
    auto newPos = start;
    advance(newPos, diff);
    bool legalWhiteMove = start->isWhite && (diff == -8 || !checkLine(newPos) && (diff == -9 || diff == -7));
    bool legalBlackMove = !start->isWhite && (diff == 8 || !checkLine(newPos) && (diff == 9 || diff == 7));
    return legalBlackMove || legalWhiteMove;
}
