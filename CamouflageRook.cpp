#include "CamouflageRook.h"

CamouflageRook::CamouflageRook(int iTeam)
	: Pieces(Pieces::Rook, iTeam) {

}

bool CamouflageRook::Move(int ax, int ay, int bx, int by) {
	if (ax == bx) {
		return Pieces::Move(ax, ay, bx, by);
	}
	else if (ay == by) {
		return Pieces::Move(ax, ay, bx, by);
	}

	return false;
}