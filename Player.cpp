#include "Player.h"
#include <string>
#include <iostream>



Player::Player(Board *board)
{
	this->board = board;
}



void Player::movePiece()
{
	std::string piecePosition;
	std::string finalPosition;
	std::cout << "Move which piece?\n";
	std::cin >> piecePosition;
	std::cout << "Move to where?\n";
	std::cin >> finalPosition;
	int initpos = calculateMove("8a", piecePosition);
	int finalpos = calculateMove("8a", finalPosition);
	int diff = finalpos - initpos;
	 
	auto start = board->begin();
	//advance(x, );
	//checkMove(board->begin(), piecePosition, finalPosition, whiteTurn);



	whiteTurn = !whiteTurn;

}

int Player::calculateMove(std::string piecePosition,std::string finalPosition) {
	int startingColumn = 8 - piecePosition[0];
	int finalColumn = 8 - finalPosition[0];
	int columnDifference = finalColumn - startingColumn;

	int startingRow = piecePosition[1] - '0';
	int finalRow = finalPosition[1] - 48;
	int rowMultiplier = finalRow - startingRow;

	return 8 * rowMultiplier + columnDifference;
}
