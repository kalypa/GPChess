#pragma once

#include "Board.h"
#include "Graphics.h"
#include "Pieces.h"

class Console {
private:
	Board board;
	Graphics graphics;

	int iTeam = Pieces::Black;

private:
	Console(Console &program);

	void ExecuteCommand(void);

public:
	Console(void);

	int Run(void);
};