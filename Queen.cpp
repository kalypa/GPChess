#include "Queen.h"

#define myabs(x) ((x) < 0 ? -(x) : (x))

Queen::Queen(unsigned int iTeam)
	: Pieces(Pieces::Queen, iTeam) {

}

bool Queen::Move(int ax, int ay, int bx, int by) const {
	if (ax == bx) {
		return Pieces::Move(ax, ay, bx, by);
	}
	else if (ay == by) {
		return Pieces::Move(ax, ay, bx, by);
	}
	else {
		if (myabs(ax - bx) == myabs(ay - by)) {
			return Pieces::Move(ax, ay, bx, by);
		}
	}

	return false;
}