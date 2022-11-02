#include "Board.h"
#include "Common.h"
#include "Game.h"
#include "Menu.h"

int main() {
	srand(time(0));
	Common::setUpConsole();
	Menu* p;
	p->mainMenu();
	Common::setConsoleColor(BLACK, WHITE);

	return 0;
}