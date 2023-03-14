#include "Console.h"
#include <Windows.h>
#include <time.h>
#include <iostream>
#include <fcntl.h>
#include <io.h>
using namespace std;
int main(void) {
	system("mode con cols=130 lines=20 | title CamouflageChess");
	_setmode(_fileno(stdout), _O_U8TEXT);
	wcout << L" ██████╗ █████╗ ███╗   ███╗ ██████╗ ██╗   ██╗███████╗██╗      █████╗  ██████╗ ███████╗     ██████╗██╗  ██╗███████╗███████╗███████╗" << endl;
	Sleep(500);
	wcout << L"██╔════╝██╔══██╗████╗ ████║██╔═══██╗██║   ██║██╔════╝██║     ██╔══██╗██╔════╝ ██╔════╝    ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << endl;
	Sleep(500);
	wcout << L"██║     ███████║██╔████╔██║██║   ██║██║   ██║█████╗  ██║     ███████║██║  ███╗█████╗      ██║     ███████║█████╗  ███████╗███████╗" << endl;
	Sleep(500);
	wcout << L"██║     ██╔══██║██║╚██╔╝██║██║   ██║██║   ██║██╔══╝  ██║     ██╔══██║██║   ██║██╔══╝      ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << endl;
	Sleep(500);
	wcout << L"╚██████╗██║  ██║██║ ╚═╝ ██║╚██████╔╝╚██████╔╝██║     ███████╗██║  ██║╚██████╔╝███████╗    ╚██████╗██║  ██║███████╗███████║███████║" << endl;
	Sleep(500);
	wcout << L" ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝ ╚═════╝  ╚═════╝ ╚═╝     ╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝     ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝ " << endl;
	wcout << endl;
	wcout << endl;
	_setmode(_fileno(stdout), _O_TEXT);
	Sleep(2000);
	system("cls");
	Console program;

	return program.Run();
}