
#include "Player.h"
//#include "Board.h"
#include <string>
#include <iostream>



Player::Player(Board* board)
{
	this->board = board;
}


void Player::movePiece()
{
	std::string piecePosition;
	std::string finalPosition;
	std::cout << (whiteTurn ? "White's turn" : "Black's turn") << std::endl;
	std::cout << "Move which piece?\n";
	std::cin >> piecePosition;
	std::cout << "Move to where?\n";
	std::cin >> finalPosition;


	auto boardBegin = board->begin();

	int diff = calculateDiff(piecePosition, finalPosition);//d
	int pieceOldPos = calculateDiff(piecePosition, "1h");
	int traverseDist;
	int pieceNewPos = calculateDiff("8a", piecePosition);

	bool allowedMove;

	
	Board::iterator newPiecePos = boardBegin;
	traverseDist = calculateDiff("8a", finalPosition);
	std::advance(newPiecePos, traverseDist);

	Board::iterator oldPicePos = boardBegin;
	traverseDist = calculateDiff("8a", piecePosition);
	std::advance(oldPicePos, traverseDist);

	allowedMove = checkMove(boardBegin, newPiecePos, oldPicePos, traverseDist, diff, whiteTurn);
	if (allowedMove) {
		newPiecePos->name = oldPicePos->name;
		newPiecePos->isWhite = oldPicePos->isWhite;
		oldPicePos->name = (board->isWhite(traverseDist)) ? '-' : '#';
		whiteTurn = !whiteTurn;
	}

	std::cout << "------------"<< std::endl;
	std::cout << "is allowed move = " << allowedMove << std::endl;
	std::cout << "diff is = " << diff << std::endl;
	std::cout << "------------" << std::endl;
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