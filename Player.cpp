
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
	std::cout << std::endl;

	if (!isAllowedInput(piecePosition, finalPosition)) return;

	auto boardBegin = board->begin();
	int diff = calculateDiff(piecePosition, finalPosition);//d
	//int pieceOldPos = calculateDiff(piecePosition, BOARD_END);//*BOARD_START instead
	int oldPosTraverseDist, newPosTraverseDist;
	int pieceNewPos = calculateDiff(BOARD_START, piecePosition);
	bool allowedMove;
	
	Board::iterator newPiecePos = boardBegin;
	newPosTraverseDist = calculateDiff(BOARD_START, finalPosition);
	std::advance(newPiecePos, newPosTraverseDist);

	Board::iterator oldPicePos = boardBegin;
	oldPosTraverseDist = calculateDiff(BOARD_START, piecePosition);
	std::advance(oldPicePos, oldPosTraverseDist);



	allowedMove = checkMove(boardBegin, newPiecePos, oldPicePos, oldPosTraverseDist, diff, whiteTurn);
	if (allowedMove) {


			if (oldPicePos->name == board->getWhiteKing()->name) {
				board->setWhiteKing(newPiecePos, newPosTraverseDist);
			}
			else if (oldPicePos->name == board->getBlackKing()->name) {
				board->setBlackKing(newPiecePos, newPosTraverseDist);
			}

			if (newPiecePos->name == 'h' || newPiecePos->name == 'H') {
				doMove(newPiecePos, oldPicePos, oldPosTraverseDist);
				board->print();
				std::cout << "\n**** CHECK MATE ****\n" << std::endl;
				exit(0);
			}
			doMove(newPiecePos, oldPicePos, oldPosTraverseDist);


			bool checkWhiteKing, checkBlackKing;
			checkWhiteKing = checkCheck(board->getWhiteKing(), board->getWhiteKingPos());
			checkBlackKing = checkCheck(board->getBlackKing(), board->getBlackKingPos());
			if (checkWhiteKing || checkBlackKing)
				std::cout << "\n*** Check! ***\n" << std::endl;


			//std::cout << "\nNew white king pos = " << board->getWhiteKingPos() << std::endl;
			//std::cout << "\nNew white king name = " << board->getWhiteKing()->name << std::endl;
			//std::cout << "\nNew black king pos = " << board->getBlackKingPos() << std::endl;
			//std::cout << "\nNew black king name = " << board->getBlackKing()->name << std::endl;


			whiteTurn = !whiteTurn;
		

	}
	else {
		std::cout << "\nNot allowed move\n" << std::endl;
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