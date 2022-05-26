#include "Arbiter.h"
#include <list>
#include <iterator>
#include <math.h>

bool checkMove(Board::iterator start, int diff, bool whiteTurn)
{
	auto end = start;
	std::advance(end, diff);
	if (start->getName() == '\0') return false;
	else if (start->getColor() != whiteTurn ||end->getName() != '\0' &&
		start->getColor() == end->getColor()) return false;

	/*switch (start->getName()) {
	case 'R':
		return checkRook(diff);
	}*/
}

bool checkKing(int diff)
{
	return false;
}

bool checkQueen(int diff)
{
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

bool checkBishop(int diff)
{
	return false;
}
bool checkLine(Board::iterator position){
    if(position->getName() !='-'||position->getName()!='#')
        return false;
    return true;
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
    if (diff%8 ==0)
        if (diff>0)
            for (int i = 0; i < diff/8; ++i) {
                advance(start,8);
                toBeReturned=checkLine(start);

            }
        if (diff<0)
            for (int i = 0; i >diff/8 ; ++i) {
                advance(start,-8);
                toBeReturned=checkLine(start);

            }


    return toBeReturned;
}


bool checkPawn(int diff)
{
	return false;
}
