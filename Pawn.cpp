#include "Pawn.h"

#define myabs(x) ((x) < 0 ? -(x) : (x))

Pawn::Pawn(unsigned int iTeam) : Pieces(Pieces::Pawn, iTeam) {

}

bool Pawn::Attack(int ax, int ay, int bx, int by) const {
	if (Team == Pieces::Black) {
		if (myabs(1 + ax) == bx && ay - 1 == by) {
			return true;
		}
	}
	else {
		if (myabs(1 - ax) == bx && ay + 1 == by) {
			return true;
		}
	}

	return false;
}

bool Pawn::Move(int ax, int ay, int bx, int by) const {
	if (Team == Pieces::Black) {
		if (ax == bx && (ay > by && ay - 2 <= by)) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}
	else {
		if (ax == bx && (ay < by && ay + 2 >= by)) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}

	return false;
}