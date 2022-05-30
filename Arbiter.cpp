#include "Arbiter.h"
#include <list>
#include <cmath>
#include <iostream>


bool checkMove(Board::iterator boardBegin, Board::iterator newPiecePos,
	Board::iterator oldPicePos, int traverseDist, int diff, bool whiteTurn) {

	/* ***TODO: Uncomment this to stop same colour pieces 
		capturing each other and to stop same colour move twice

	if (oldPicePos->isWhite != whiteTurn) {
		std::cout << "\nIt is not your turn" << std::endl;
		return false;
	}
	else if (!checkEmpty(newPiecePos) && (newPiecePos->isWhite == oldPicePos->isWhite)) {
		std::cout << "\nCan't capture same colour piece." << std::endl;
		return false;
	}
	*/


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
		return checkBishop(oldPicePos, diff);
	case 'b':
		return checkBishop(oldPicePos, diff);
	case 'Q':
		return checkQueen(oldPicePos, diff);
	case 'q':
		return checkQueen(oldPicePos, diff);
	case 'H':
		return checkKing(oldPicePos, diff);
	case 'h':
		return checkKing(oldPicePos, diff);
	case 'P':
		return checkPawn(oldPicePos, diff,traverseDist);
	case 'p':
		return checkPawn(oldPicePos, diff, traverseDist);
	default: return false;
	};
}
bool checkKing(Board::iterator piecePosition, int diff)
{
	if (abs(diff) <= 9 && checkQueen(piecePosition, diff))
		return true;

	return false;
}
//TODO: to stop queen jumping over pieces stop rook and bishop first first (check its todo)
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
{bool toBeReturned=false;
int iterations = abs(diff) / 9;
    if (abs(diff)%9==0){
        toBeReturned=true;
        for (int i = 0; i < iterations; ++i) {
            std::advance(piecePosition,9* abs(diff)/diff);
			if (i + 1 == iterations && toBeReturned)
				return true;
            toBeReturned=checkEmpty(piecePosition);
			//**TODO: uncomment bottom line to stop bishop jump over/skip other pieces
			//if (!toBeReturned) return false;
        }
    }
    if(abs(diff)%7==0){
        toBeReturned=true;
		iterations = abs(diff) / 7;
        for (int i = 0; i < iterations; ++i) {
			if (i + 1 == iterations && toBeReturned)
				return true;
            std::advance(piecePosition,7*abs(diff)/diff);
            toBeReturned=checkEmpty(piecePosition);
			//**TODO: uncomment bottom line to stop bishop jump over/skip other pieces
			//if (!toBeReturned) return false;
        }				

    }
	return toBeReturned;
}

bool checkRook(Board::iterator piecePosition ,int diff)
{bool toBeReturned= false;
int iterations;


    if (abs(diff)<8) {
        toBeReturned=true;
		iterations = abs(diff);
            for (int i = 0; i < iterations; ++i) {
				if (i + 1 == iterations && toBeReturned)
					return true;

                std::advance(piecePosition,abs(diff)/diff);
                toBeReturned = checkEmpty(piecePosition);
				//**TODO: uncomment bottom line to stop rook jump over/skip other pieces
				//if (!toBeReturned) return false;
            }
    }


	if (diff % 8 == 0) {
		toBeReturned = true;
		iterations = abs(diff) / Board::DIM;

		for (int i = 0; i < iterations; ++i) {
			if (i + 1 == iterations && toBeReturned) 
				return true;

			advance(piecePosition, 8 * abs(diff) / diff);
			toBeReturned = checkEmpty(piecePosition);
			//**TODO: uncomment bottom line to stop rook jump over/skip other pieces
			//if (!toBeReturned) return false;
		}
	}
    return toBeReturned;

	/*tests
	  1a 3a
	  3a 3d
	  3d 3a
	*/
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
	bool legalWhite = piecePosition->isWhite && (white1step && checkEmpty(newPos) || white2step && checkEmpty(newPos) || whiteTake);
	bool legalBlack = !piecePosition->isWhite && (black1step && checkEmpty(newPos) || black2step && checkEmpty(newPos) || blackTake);
    return legalBlack || legalWhite;
}

bool checkEmpty(Board::iterator position) {
	if (position->name == '-' || position->name == '#')
		return true;
	return false;
}

bool checkCheck(Board::iterator King, int kingPosition)
{   int directions[] {1,-1,8,-8,7,-7,9,-9,6,-6,15,-15,17,-17,10,-10};
	enum Pieces{Q=0,R=1,B=2,P=3,K=4};
    char pieces[]{'Q','R','B','P','K'};
    if(King->isWhite)
        for(char& piece:pieces)
            piece= tolower(piece);
    int counter =0;
	for (int direction : directions) {
		counter++;

		auto currentCheckLocation = King;
		int j = 0;
		while (j < 8) {
			j++;

			if (kingPosition + direction < Board::BOARD_SIZE) {
				std::advance(currentCheckLocation, direction);
				//std::cout << currentCheckLocation->name << std::endl;

				if (!checkEmpty(currentCheckLocation))
					break;//to check if what is encountered is different colour and then eventually break

				if (counter < 5) {
					if (checkEmpty(currentCheckLocation) == pieces[Q] || checkEmpty(currentCheckLocation) == pieces[R])
						return true;
				}
				else if (counter < 9) {
					if (checkEmpty(currentCheckLocation) == pieces[Q] || checkEmpty(currentCheckLocation) == pieces[B])
						return true;
					if (j == 1 && checkEmpty(currentCheckLocation) == pieces[P])
						return true;

				}
				else
					if (checkEmpty(currentCheckLocation) == pieces[K])
						return true;
			}
			else break;
		}
	}
    return false;
    }


/*
	1. Copy the king position
	2. 

*/


void doMove(const Board::iterator newPiecePos, const Board::iterator oldPicePos, const int oldPosTraverseDist) {
	newPiecePos->name = oldPicePos->name;
	newPiecePos->isWhite = oldPicePos->isWhite;
	oldPicePos->name = (isWhite(oldPosTraverseDist + 1)) ? '-' : '#';
}
void undoMove(const Board::iterator newPiecePos, const Board::iterator oldPicePos,const int oldPosTraverseDist, const int diff) {
	oldPicePos->name = newPiecePos->name;
	oldPicePos->isWhite = newPiecePos->isWhite;
	newPiecePos->name = (isWhite((oldPosTraverseDist + diff) + 1) ? '-' : '#');

	//std::cout << "oldPicePos->name" << oldPicePos->name << std::endl;
	//std::cout << "oldPicePos->isWhite" << oldPicePos->isWhite << std::endl;
	//std::cout << "newPiecePos->name" << newPiecePos->name << std::endl;
}