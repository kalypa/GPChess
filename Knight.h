#pragma once

#include "Pieces.h"

class Knight : public Pieces {
public:
	Knight(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};