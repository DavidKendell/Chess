#pragma once
#include<list>
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct Piece
{
	char name;
	bool color;

};
list <Piece> board;
const unsigned int DIM = 8;
const unsigned int BOARD_SIZE = DIM * DIM;



bool isWhite(int cellNum) {

	bool isBlank = true;
	for (int i = 1; i < cellNum; i++) {
		if (i % DIM == 0) continue;
		isBlank = (isBlank) ? false: true;
	}
	return isBlank;
}


void display() {
	int counter = 1;
	int negCount = 8;
	
	cout << "|";
	for (auto it = board.begin(); it != board.end(); ++it) {
		cout << " " << it->name << " ";
		if (counter % DIM == 0) {
			cout  << "|"<< negCount << "\n|"  ;
			negCount --;
		}
		counter++;

	}
	cout << "------------------------" << endl;
	cout << "  A  B  C  D  E  F  G  H " << endl;
}

void init() {
	char names[]{ 'R','K','B','Q','H','B','K','R'};


	for (int i = 0; i < DIM*DIM; i++) {
		Piece p;

		if (i < DIM) {
			p.name = names[i];
			p.color = true;
		}else if(i < 2*DIM){
			p.name = 'P';
			p.color = true;
		}
		else if (i > 2*DIM-1 && i < BOARD_SIZE-2*DIM) {
			p.color = isWhite(i+1);
			p.name = (p.color) ? '-' : '#';
		}
		else if (i > BOARD_SIZE - 2*DIM-1 && i < BOARD_SIZE-DIM) {
			p.name = 'p';
		}
		else {
			p.name = tolower(names[i % DIM]);
		}
		board.push_back(p);

	}

}


/*
Functions needed:

Move logic - calculate next position					int nextPos(Peace p);
Move logic2 - set up the allowed moves for each piece	bool isAllowedMove(Peace p);

Figures initial setup positioning						void init() --->done
Kill logic												void capturePiece(int pos);
Input - gameplay control								void makeTurn();
Output - statistics										void showStatistics();

*/