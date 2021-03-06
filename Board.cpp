#include "Board.h"
#include <iostream>


Board::Board()
{
	char names[]{ 'R','K','B','Q','H','B','K','R' };


	for (int i = 0; i < DIM * DIM; i++) {
		Piece p;

		if (i < DIM) {
			p.name = names[i];
		}
		else if (i < 2 * DIM) {
			p.name = 'P';
		}
		else if (i > 2 * DIM - 1 && i < BOARD_SIZE - 2 * DIM) {
			p.name = (isWhite(i + 1)) ? '-' : '#';
		}
		else if (i > BOARD_SIZE - 2 * DIM - 1 && i < BOARD_SIZE - DIM) {
			p.name = 'p';
			p.isWhite = true;
		}
		else {
			p.name = tolower(names[i % DIM]);
			p.isWhite = true;
		}
		Board::push_back(p);

	}

	whiteKing = Board::end();
	advance(whiteKing, -4);
	whiteKingPosiiton = 60;
	blackKing = Board::begin();
	advance(blackKing, 4);
	blackKingPosition = 4;
}


std::list<Piece>::iterator Board::getWhiteKing()const {
	return whiteKing;
}

std::list<Piece>::iterator Board::getBlackKing()const {
	return blackKing;
}
int Board::getWhiteKingPos()const {
	return whiteKingPosiiton;
}
int Board::getBlackKingPos()const {
	return blackKingPosition;
}
void Board::setWhiteKing(const std::list<Piece>::iterator& _whiteKing, int kingPos) {
	whiteKing = _whiteKing;
	whiteKingPosiiton = kingPos;
}
void Board::setBlackKing(const std::list<Piece>::iterator& blackKing, int kingPos) {
	Board::blackKing = blackKing;
	Board::blackKingPosition = kingPos;
}


void Board::print()
{
	int newLineCounter = 1;
	int rowNum = 8;
	std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
	std::cout << "  ------------------------" << std::endl;
	std::cout << rowNum << "|";
	for (auto it = Board::begin(); it != Board::end(); ++it) {
		std::cout << " " << it->name << " ";
		if (newLineCounter % DIM == 0) {
			std::cout << "|" << rowNum << "\n";
			if (newLineCounter < BOARD_SIZE) {
				std::cout << rowNum - 1 << "|";
			}
			rowNum--;
		}
		newLineCounter++;

	}
	std::cout << "  ------------------------" << std::endl;
	std::cout << "   A  B  C  D  E  F  G  H " << std::endl;
}

bool isWhite(int cellNum) {

	bool isBlank = true;
	for (int i = 1; i < cellNum; i++) {
		if (i % Board::DIM == 0) continue;
		isBlank = (isBlank) ? false : true;
	}
	return isBlank;
}

