#pragma once
#include "Board.h"
#include <string>

//bool checkMove(Board::iterator begin, Board::iterator initpos, int diff, bool playerColour);
bool checkMove(Board::iterator boardBegin, Board::iterator newPiecePos, Board::iterator oldPicePos, int traverse, int diff, bool whiteTurn);
bool checkKing(Board::iterator initpos, int diff);
bool checkQueen(Board::iterator initpos, int diff);
bool checkKnight(Board::iterator initpos, int diff);
bool checkBishop(Board::iterator initpos, int diff);
bool checkRook(Board::iterator initpos, int diff);
bool checkPawn(Board::iterator initpos, int diff, int traverseDist);
bool checkEmpty(Board::iterator);
//bool checkCheck(Board::iterator King);
bool checkCheck(Board::iterator King, int kingPosition);
void doMove(const Board::iterator newPiecePos, const Board::iterator oldPicePos, const int oldPosTraverseDist);
void undoMove(const Board::iterator newPiecePos, const Board::iterator oldPicePos, const int oldPosTraverseDist, const int diff);
