#pragma once
#include <list>
#include "Piece.h"
class Board : public std::list<Piece>
{
public:
	Board();
	void print();
};

