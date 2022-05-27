#include "Board.h"
#include <iostream>


Board::Board()
{
	char names[]{ 'R','K','B','Q','H','B','K','R' };


	for (int i = 0; i < DIM * DIM; i++) {
		Piece p;

		if (i < DIM) {
			p.name = names[i];
			p.isWhite = true;

		}
		else if (i < 2 * DIM) {
			p.name = 'P';
			p.isWhite = true;
		}
		else if (i > 2 * DIM - 1 && i < BOARD_SIZE - 2 * DIM) {
			p.isWhite = isWhite(i + 1);
			p.name = (p.isWhite) ? '-' : '#';
		}
		else if (i > BOARD_SIZE - 2 * DIM - 1 && i < BOARD_SIZE - DIM) {
			p.name = 'p';

		}
		else {
			p.name = tolower(names[i % DIM]);

		}
		Board::push_back(p);

	}
}

void Board::print()
{
	int newLineCounter = 1;
	int rowNum = 8;

	std::cout << "|";
	for (auto it = Board::begin(); it != Board::end(); ++it) {
		std::cout << " " << it->name << " ";
		if (newLineCounter % DIM == 0) {
			std::cout << "|" << rowNum << "\n|";
			rowNum--;
		}
		newLineCounter++;

	}
	std::cout << "------------------------" << std::endl;
	std::cout << "  A  B  C  D  E  F  G  H " << std::endl;
}

bool Board::isWhite(int cellNum) {

	bool isBlank = true;
	for (int i = 1; i < cellNum; i++) {
		if (i % DIM == 0) continue;
		isBlank = (isBlank) ? false : true;
	}
	return isBlank;
}

