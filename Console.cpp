#include <iostream>
#include <string>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include "Console.h"
#include "Board.h"
#include "Pieces.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "CamouflageQueen.h"
#include "CamouflageBishop.h"
#include "CamouflageKnight.h"
#include "CamouflageRook.h"
#include "CamouflagePawn.h"
using namespace std;

Console::Console(Console &program) : graphics(&board) {
}

Console::Console(void) : graphics(&board) {
}

void Console::ExecuteCommand(void) {
	const wstring fWord[2] = { L" ██╗",  L"██████╗ " };
	const wstring dWord[2] = { L"███║",  L"╚════██╗" };
	const wstring tWord[2] = { L"╚██║",  L" █████╔╝" };
	const wstring qWord[2] = { L" ██║",  L"██╔═══╝ " };
	const wstring pWord[2] = { L" ██║",  L"███████╗" };
	const wstring hWord[2] = { L" ╚═╝",  L"╚══════╝" };
	string param[2];
	int x[2] = { 0, };
	int y[2] = { 0, };
	Pieces* pTarget = 0;
	Pieces* pTarget2 = 0;
	cout << "Player" << iTeam + 1 << " 의 차례입니다. " << endl;
	cout << "                                                       이동시킬 말의 위치: ";
	cin >> param[0];
	cout << "                                                       말을 이동시킬 위치: ";
	cin >> param[1];

	x[0] = param[0][0] - 'A';
	y[0] = 7 - (param[0][1] - '1');
	x[1] = param[1][0] - 'A';
	y[1] = 7 - (param[1][1] - '1');

	pTarget = board.GetPiece(x[0], y[0]);
	pTarget2 = board.GetPiece(x[0], y[0]);
	if (pTarget != nullptr)
	{
		if (pTarget->Team == iTeam) {
			if (board.GetPiece(x[1], y[1]) && pTarget->Team == iTeam ) {
				if (pTarget->Attack(x[1], y[1], x[0], y[0]) && board.GetPiece(x[1], y[1])->Team != iTeam) {
					if (pTarget->Type == 0)
					{
						pTarget2->Type = 0;
						if (board.MoveTo(x[1], y[1], x[0], y[0]))
						{
							iTeam = !iTeam;
						}
					}
					else if (pTarget->Type != 0)
					{
					    pTarget2->Type = board.GetPiece(x[1], y[1])->Type;
					    if (board.MoveTo(x[1], y[1], x[0], y[0]))
					    {
					    	iTeam = !iTeam;
					    }
					    if (pTarget->Type == 0)
					    {
					    	system("cls");
					    	_setmode(_fileno(stdout), _O_U8TEXT);
					    	wcout << L"                      ██████╗ ██╗      █████╗ ██╗   ██╗███████╗██████╗   " << fWord[!iTeam] << L"   ██╗    ██╗██╗███╗   ██╗ ██╗" << endl;
					    	wcout << L"                      ██╔══██╗██║     ██╔══██╗╚██╗ ██╔╝██╔════╝██╔══██╗  " << dWord[!iTeam] << L"   ██║    ██║██║████╗  ██║ ██║" << endl;
					    	wcout << L"                      ██████╔╝██║     ███████║ ╚████╔╝ █████╗  ██████╔╝  " << tWord[!iTeam] << L"   ██║ █╗ ██║██║██╔██╗ ██║ ██" << endl;
					    	wcout << L"                      ██╔═══╝ ██║     ██╔══██║  ╚██╔╝  ██╔══╝  ██╔══██╗  " << qWord[!iTeam] << L"   ██║███╗██║██║██║╚██╗██║ ╚═╝" << endl;
					    	wcout << L"                      ██║     ███████╗██║  ██║   ██║   ███████╗██║  ██║  " << pWord[!iTeam] << L"   ╚███╔███╔╝██║██║ ╚████║ ██╗" << endl;
					    	wcout << L"                      ╚═╝     ╚══════╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝  " << hWord[!iTeam] << L"    ╚══╝╚══╝ ╚═╝╚═╝  ╚═══╝ ╚═╝" << endl;
					    	_setmode(_fileno(stdout), _O_TEXT);
					    	exit(0);
					    }
					    else if (pTarget->Type != 0)
					    {
					    	if (pTarget->Type < 6)
					    	{
					    		pTarget->Type = pTarget2->Type + 5;
					    	}
					    	else
					    	{
					    		pTarget->Type = pTarget2->Type;
					    	}
					    }
				    }
				}
			}
			else {
				if (pTarget->Move(x[1], y[1], x[0], y[0])) {
					if (board.MoveTo(x[1], y[1], x[0], y[0])) {
						iTeam = !iTeam;
					}
				}
			}
		}
	}
	return;
}

int Console::Run(void) {
	while (true) {
		std::system("cls");
		graphics.Render();
		
		ExecuteCommand();
		
	}

	return 0;
}