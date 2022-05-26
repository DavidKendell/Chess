#include "Player.h"
#include <string>
#include <iostream>



Player::Player(Board *board)
{
	this->board = board;
}

void Player::movePiece()
{
	std::string start;
	std::string end;
	std::cout << "Move which piece?\n";
	std::cin >> start;
	std::cout << "Move to where?\n";
	std::cin >> end;
	
	//int startind = math start
	//endind = math end
	//diff
	// checkMove(iterator, diff, whiteTurn)
	//edit board

	whiteTurn = !whiteTurn;

}
