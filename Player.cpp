
#include "Player.h"
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
	std::cout << "Choose piece to move\n";
	std::cin >> piecePosition;
	std::cout << "Move to where?\n";
	std::cin >> finalPosition;

	if (!isAllowedInput(piecePosition, finalPosition)) return;

	auto boardBegin = board->begin();

	int diff = calculateDiff(piecePosition, finalPosition);//d
	//int pieceOldPos = calculateDiff(piecePosition, BOARD_END);//*BOARD_START instead
	int traverseDist;
	int pieceNewPos = calculateDiff(BOARD_START, piecePosition);

	bool allowedMove;
	
	Board::iterator newPiecePos = boardBegin;
	traverseDist = calculateDiff(BOARD_START, finalPosition);
	std::advance(newPiecePos, traverseDist);


	Board::iterator oldPicePos = boardBegin;
	traverseDist = calculateDiff(BOARD_START, piecePosition);
	std::advance(oldPicePos, traverseDist);

	allowedMove = checkMove(boardBegin, newPiecePos, oldPicePos, traverseDist, diff, whiteTurn);
	if (allowedMove) {

		if (oldPicePos->name == Board::whiteKing->name) {
			Board::whiteKing = newPiecePos;
		}
		else if (oldPicePos->name == Board::blackKing->name) {
			Board::blackKing = newPiecePos;
		}

		newPiecePos->name = oldPicePos->name;
		newPiecePos->isWhite = oldPicePos->isWhite;
		oldPicePos->name = (board->isWhite(traverseDist+1)) ? '-' : '#';

		//checkCheck(Board::whiteKing);


		whiteTurn = !whiteTurn;
	}

	//std::cout << "------------"<< std::endl;
	//std::cout << "is allowed move = " << allowedMove << std::endl;
	//std::cout << "diff is = " << diff << std::endl;
	//std::cout << "------------" << std::endl;
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

bool Player::isAllowedInput(std::string piecePosition, std::string finalPosition) {
	std::string userInput = piecePosition + finalPosition;
	std::string boardNotation = "12345678abcdefgh";
	for (char& input : userInput) {
		if (boardNotation.find(input) == std::string::npos) {
			std::cout << "\n\nOnly board notation moves allowed (lowercase)\n" << std::endl;
			return false;
		}
	}
	if (!isdigit(piecePosition[0]) || !isdigit(finalPosition[0]) ||
		!isalpha(piecePosition[1]) || !isalpha(finalPosition[1])) {
		std::cout << "\n\nCommands need to be single digit followed by single character.\n" << std::endl;
		return false;
	}

	return true;

}