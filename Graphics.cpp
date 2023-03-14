#include <Windows.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>
#include "Board.h"
#include "Graphics.h"
#include "Pieces.h"
#include <wchar.h>

Graphics::Graphics(const Board *pBoard) : pBoard(pBoard) {
}

void Graphics::Render(void) const {
	using namespace std;

	const char szBottom[] = "ABCDEFGH";

	const Pieces* pTarget = 0;
	_setmode(_fileno(stdout), _O_U8TEXT);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	wcout << L"                                          ╔═╗┌─┐┌┬┐┌─┐┬ ┬┌─┐┬  ┌─┐┌─┐┌─┐  ╔═╗┬ ┬┌─┐┌─┐┌─┐" << endl;
	wcout << L"                                          ║  ├─┤││││ ││ │├┤ │  ├─┤│ ┬├┤   ║  ├─┤├┤ └─┐└─┐" << endl;
	wcout << L"                                          ╚═╝┴ ┴┴ ┴└─┘└─┘└  ┴─┘┴ ┴└─┘└─┘  ╚═╝┴ ┴└─┘└─┘└─┘" << endl;
	wcout << L"ㅤㅤㅤ                                               ㅤ";
	_setmode(_fileno(stdout), _O_TEXT);
	for (int i = 0; i <= 8; i++) {
		for (int j = 0; j <= 8; j++) {
			if (i == 8) {
				if (j == 0) {
					cout << "  ";
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
					cout << szBottom[j - 1] << " ";
				}
				continue;
			}
			if (j == 0) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
				cout << 8 - i << " ";
			}
			else {
				pTarget = pBoard->GetPiece(j - 1, i);
				if (pTarget && pTarget->Team == Pieces::Black) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE | FOREGROUND_INTENSITY);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				}
				_setmode(_fileno(stdout), _O_U8TEXT);

				wcout << ToChar(pTarget);
				_setmode(_fileno(stdout), _O_TEXT);
			}
		}
		cout << endl;
		cout << "                                                       ";
	}

	return;
}

const wchar_t* Graphics::ToChar(const Pieces* pPiece) {
	if (pPiece == 0) {
		return L"ㅤ";
	}
	else {
		switch (pPiece->Type) {
		case Pieces::King:
			return L"♔ ";
		case Pieces::Queen:
			return L"♕ ";
		case Pieces::Bishop:
			return L"♗ ";
		case Pieces::Knight:
			return L"♘ ";
		case Pieces::Rook:
			return L"♖ ";
		case Pieces::Pawn:
			return L"♙ ";
		case Pieces::CamouflageQueen:
			return L"♛ ";
		case Pieces::CamouflageBishop:
			return L"♝ ";
		case Pieces::CamouflageKnight:
			return L"♞ ";
		case Pieces::CamouflageRook:
			return L"♜ ";
		case Pieces::CamouflagePawn:
			return L"♟ ";
		default:
			return 0;
		}
	}

	return 0;
}