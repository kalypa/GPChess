#include "Pieces.h"

Pieces::Pieces(unsigned int iType, unsigned int iTeam) : iType(iType), iTeam(iTeam) {
}

Pieces::Pieces(const Pieces &piece) : iType(piece.Type), iTeam(piece.Team) {
}

bool Pieces::Attack(int ax, int ay, int bx, int by) const {
	return Pieces::Move(ax, ay, bx, by);
}

bool Pieces::Move(int ax, int ay, int bx, int by) const {
	return (!(ax < 0 || ax >= 8 || ay < 0 || ay >= 8)) && (!(ax == bx && ay == by));
}