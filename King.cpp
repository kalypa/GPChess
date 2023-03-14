#include "King.h"

King::King(unsigned int iTeam)
	: Pieces(Pieces::King, iTeam) {
}

bool King::Move(int ax, int ay, int bx, int by) const {
	if (ax >= bx - 1 && ax <= bx + 1) {
		if (ay >= by - 1 && ay <= by + 1) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}

	return false;
}