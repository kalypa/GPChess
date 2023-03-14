#pragma once

#include "Pieces.h"

class CamouflageKnight : public Pieces {
public:
	CamouflageKnight(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};