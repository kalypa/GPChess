#pragma once

#include "Pieces.h"

class Rook : public Pieces {
public:
	Rook(int iTeam);

	bool Move(int ax, int ay, int bx, int by);
};