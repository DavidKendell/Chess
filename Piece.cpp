#include "Piece.h"

char Piece::getName()
{
	return name;
}

bool Piece::getColor()
{
	return isWhite;
}

Piece::Piece(char name, bool isWhite)
{
	this->name = name;
	this->isWhite = isWhite;
}
