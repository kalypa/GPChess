#include "Knight.h"


#define myabs(x) ((x) < 0 ? -(x) : (x))

Knight::Knight(unsigned int iTeam)
	: Pieces(Pieces::Knight, iTeam) {

}

bool Knight::Move(int ax, int ay, int bx, int by) const {
	if (myabs(1 - bx) == ax) {
		if (myabs(2 - by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
		else if (myabs(2 + by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}
	else if (myabs(2 - bx) == ax) {
		if (myabs(1 - by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
		else if (myabs(1 + by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}
	else if (myabs(1 + bx) == ax) {
		if (myabs(2 - by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
		else if (myabs(2 + by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}
	else if (myabs(2 + bx) == ax) {
		if (myabs(1 - by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
		else if (myabs(1 + by) == ay) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}
	return false;
}