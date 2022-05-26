#include "Player.h"
int main() {
	Board board;
	Player player(&board);
	while (true) {
		board.print();
		player.movePiece();
	}
}