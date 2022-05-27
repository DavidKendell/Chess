#pragma once
#include "Board.h"
#include <string>

bool checkMove(Board::iterator begin, Board::iterator initpos, int diff, bool playerColour);
bool checkKing(Board::iterator initpos, int diff);
bool checkQueen(Board::iterator initpos, int diff);
bool checkKnight(Board::iterator initpos, int diff);
bool checkBishop(Board::iterator initpos, int diff);
bool checkRook(Board::iterator initpos, int diff);
bool checkPawn(Board::iterator initpos, int diff);
bool checkEmpty(Board::iterator);