#pragma once

#include "Pieces.h"

class Bishop : public Pieces {
public:
	Bishop(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};