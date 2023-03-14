#pragma once

#include "Pieces.h"

class CamouflageBishop : public Pieces {
public:
	CamouflageBishop(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
};