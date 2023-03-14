#pragma once

#include "Pieces.h"

class CamouflageQueen : public Pieces {
public:
	CamouflageQueen(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};