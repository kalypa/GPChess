#pragma once

#include "Pieces.h"

class King : public Pieces {
private:
	bool bFirst = true;

public:
	King(unsigned int iTeam);

	bool Move(int ax, int ay, int bx, int by) const;

	friend class ChessBoard;
};