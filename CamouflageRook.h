#pragma once

#include "Pieces.h"

class CamouflageRook : public Pieces {
public:
	CamouflageRook(int iTeam);

	bool Move(int ax, int ay, int bx, int by);
};