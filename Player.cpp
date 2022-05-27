#include "Player.h"
//#include "Board.h"
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
	//int initpos = calculateMove("8a", piecePosition);
	//int finalpos = calculateMove("8a", finalPosition);
	//int diff = finalpos - initpos;
	 
	auto boardBegin = board->begin();

	int diff = calculateDiff(piecePosition, finalPosition);//d
	int pieceOldPos = calculateDiff(piecePosition, "1h");
	int traverseDist;
	int pieceNewPos = calculateDiff("8a", piecePosition);
	if (pieceNewPos < pieceOldPos) {
		traverseDist = calculateDiff("8a", piecePosition);
	}
	else traverseDist = calculateDiff("8a", finalPosition);


	bool allowedMove;

	whiteTurn = !whiteTurn;
	Board::iterator newPiecePos = boardBegin;
	std::advance(newPiecePos, traverseDist);

	Board::iterator oldPicePos = newPiecePos;
	std::advance(oldPicePos, -(diff));

	allowedMove = checkMove(boardBegin, newPiecePos, oldPicePos, traverseDist, diff , whiteTurn);
	if (allowedMove) {
		newPiecePos->name = oldPicePos->name;
		oldPicePos->name = (board->isWhite(traverseDist)) ? '-' : '#';
	}

}


int Player::calculateDiff(std::string piecePosition, std::string finalPosition) {
	int startingColumn = piecePosition[0] - 48;
	int finalColumn = finalPosition[0] - 48;
	int startingRow = piecePosition[1];
	int finalRow = finalPosition[1];
	int resultColumn = (startingColumn - finalColumn) * Board::DIM;
	int resultRow = startingRow - finalRow;
	int newPos = resultColumn - resultRow;

	return newPos;
}