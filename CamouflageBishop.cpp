#include "CamouflageBishop.h"
#define myabs(x) ((x) < 0 ? -(x) : (x))

CamouflageBishop::CamouflageBishop(unsigned int iTeam) : Pieces(Pieces::CamouflageBishop, iTeam) {

}

bool CamouflageBishop::Move(int ax, int ay, int bx, int by) const {
	if (myabs(ax - bx) == myabs(ay - by)) {
		return Pieces::Move(ax, ay, bx, by);
	}

	return false;
}