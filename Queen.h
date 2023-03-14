#pragma once

#include "Pieces.h"

class Queen : public Pieces {
public:
	Queen(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};