#pragma once

class Pieces;
class Board;

class Graphics {
private:
	const Board *pBoard = 0;

public:
	Graphics(const Board *pBoard);

	void Render(void) const;
	const static wchar_t* ToChar(const Pieces *pPiece);
};