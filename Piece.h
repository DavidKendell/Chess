#pragma once
class Piece
{
private:
	char name;
	bool isWhite;
public:
	char getName();
	bool getColor();
	Piece(char name, bool isWhite);
};

