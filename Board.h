#pragma once
class Pieces;

class Board {

public:
	Pieces *pBoard[8][8];
	Board(bool bStd = true);
	~Board(void);

	Pieces *GetPiece(int x, int y);
	const Pieces *GetPiece(int x, int y) const ;

	bool MoveTo(int ax, int ay, int bx, int by);
};