#pragma once

#include "Pieces.h"

class CamouflagePawn : public Pieces {
private:
	bool bFirst = true;

public:
	CamouflagePawn(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;
	bool Attack(int ax, int ay, int bx, int by) const;

	friend class ChessBoard;
};