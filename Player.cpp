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
	 
	auto start = board->begin();
	//advance(x, );
	//checkMove(board->begin(), piecePosition, finalPosition, whiteTurn);

	whiteTurn = !whiteTurn;

}

int Player::calculateMove(std::string piecePosition,std::string finalPosition) {
	int startingColumn = piecePosition[0];
	int finalColumn = finalPosition[0];
	int columnDifference = startingColumn - finalColumn;

	int startingRow = piecePosition[1] - 48;
	int finalRow = finalPosition[1] - 48;
	int rowMultiplier = startingRow - finalRow;

	return 8 * rowMultiplier + columnDifference;
}
