#pragma once

class ChessBoard;

class Pieces {
private:
	unsigned int iType;
	unsigned int iTeam;

public:
	enum {
		King = 0,
		Queen = 1,
		Bishop = 2,
		Knight = 3,
		Rook = 4,
		Pawn = 5,
		CamouflageQueen = 6,
		CamouflageBishop = 7,
		CamouflageKnight = 8,
		CamouflageRook = 9,
		CamouflagePawn = 10
	};

	enum {
		Black = 0,
		White = 1
	};

protected:
	Pieces(unsigned int iType, unsigned int iTeam);

public:
	Pieces(const Pieces &piece);

	virtual bool Move(int ax, int ay, int bx, int by) const;
	virtual bool Attack(int ax, int ay, int bx, int by) const;

public:  
	unsigned int &Type = iType;
	unsigned int &Team = iTeam;
};

