#include "Bishop.h"
#define myabs(x) ((x) < 0 ? -(x) : (x))

Bishop::Bishop(unsigned int iTeam) : Pieces(Pieces::Bishop, iTeam) {

}

bool Bishop::Move(int ax, int ay, int bx, int by) const {
	if (myabs(ax - bx) == myabs(ay - by)) {
		return Pieces::Move(ax, ay, bx, by);
	}

	return false;
}