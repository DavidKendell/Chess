#pragma once
#include "Board.h"
#include <string>

bool checkMove(Board::iterator start, int diff, bool playerColour);
bool checkKing(int diff);
bool checkQueen(int diff);
bool checkKnight(int diff);
bool checkBishop(int diff);
bool checkRook(int diff);
bool checkPawn(int diff);