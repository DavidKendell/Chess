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
	int diff = 3;
	auto initpos = board->begin();
	advance(initpos, diff);
	if (checkMove(board->begin(), initpos, diff, whiteTurn)) {
		//move
	}

	//edit board
	whiteTurn = !whiteTurn;

}
