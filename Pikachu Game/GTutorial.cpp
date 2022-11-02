#include "GTutorial.h"

//=======TUTORIAL PAGE 1: INTRO==========
void Tutorial1() {
	Common::showCursor(false);

	Common::setConsoleColor(BLACK, YELLOW);
	Common::gotoXY(34, 3);
	cout << "HOW TO PLAY";

	Common::setConsoleColor(LIGHT_AQUA, BLACK);
	Common::gotoXY(34, 5);
	cout << "INTRODUCTION";
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	//=======Tao bien tren========
	Common::gotoXY(2, 5);
	for (int i = 1; i <= 34 - 3; i++) {
		if (i == 1)
			putchar(218);	//goc trai tren
		else
			putchar(196);	//gach ngang
	}

	Common::gotoXY(47, 5);
	for (int i = 1; i <= 30; i++) {
		if (i == 30)
			putchar(191);	//goc phai tren
		else
			putchar(196);	//gach ngang
	}
	//========Tao bien 2 ben=========
	int j;
	for (j = 6; j <= 13; j++) {
		Common::gotoXY(2, j);
		if (j == 13)
			putchar(192);	// goc trai duoi
		else
			putchar(179);	// cot doc trai
	}

	for (j = 6; j <= 13; j++) {
		Common::gotoXY(76, j);
		if (j == 13)
			putchar(217);	// goc phai duoi
		else
			putchar(179);	//cot doc phai
	}

	//==========Tao bien duoi=============
	Common::gotoXY(2 + 1, 13);
	for (int i = 1; i <= 73; i++)
		putchar(196);

	Common::setConsoleColor(BLACK, PURPLE);

	Common::gotoXY(6, 7);
	cout << " Welcome to our Matching Game! This game is just like the original ";
	Common::gotoXY(4, 8);
	cout << "Pikachu Matching Game, which enables the player to find and pick a pair";
	Common::gotoXY(4, 9);
	cout << "of cells containing the same Pokemon and connecting to each other with";
	Common::gotoXY(4, 10);
	cout << "a particular pattern. But in this game, you will experience the more";
	Common::gotoXY(4, 11);
	cout << "simplified version of it with characters instead of Pokemon figures.";

	Common::gotoXY(1, 14);
	cout << endl;

	//========Tao nut BACK NEXT============
	char key;

	while (true) {
		Common::gotoXY(1, 1);
		putchar(60);
		putchar(205);
		cout << " BACK";

		Common::gotoXY(70, 1);
		cout << "NEXT ";
		putchar(205);
		putchar(62);

		key = _getch();

		if (key == 75 || tolower(key) == 'a') {
			system("cls");
			Menu::mainMenu();
			break;
		}
		if (key == 77 || tolower(key) == 'd') {
			system("cls");
			Tutorial2();
			break;
		}
	}
}

//=======TUTORIAL PAGE 2: MOVE & CHOOSE==========
void drawKeyboardMove(int x, int y, int Hpercell, int Wpercell, char up, char down, char right, char left) {
	Common::gotoXY(x + Wpercell, y);
	putchar(218);			//goc trai tren
	for (int i = x + Wpercell + 1; i <= x + 2 * Wpercell; i++) {
		if (i != x + 2 * Wpercell)
			putchar(196);		//bien ngang
		else
			putchar(191);		//goc phai tren
	}

	//tao bien phim len
	for (int i = y + 1; i < y + Hpercell; i++) {
		Common::gotoXY(x + Wpercell, i);
		putchar(179);			//bien doc
	}
	for (int i = y + 1; i < y + Hpercell; i++) {
		Common::gotoXY(x + 2 * Wpercell, i);
		putchar(179);			//bien doc
	}

	Common::gotoXY(x, y + Hpercell);
	putchar(218);				//goc trai tren
	for (int i = x + 1; i <= x + Wpercell * 3; i++) {
		if (i == x + Wpercell * 3)
			putchar(191);		//goc phai tren
		else if ((i - x) % Wpercell == 0)
			putchar(197);		//goc nga 4
		else
			putchar(196);		//bien ngang
	}
	for (int k = 0; k <= 3; k++) {
		for (int i = y + Hpercell + 1; i < y + Hpercell * 2; i++) {
			Common::gotoXY(x + Wpercell * k, i);
			putchar(179);		//bien doc
		}
	}

	Common::gotoXY(x, y + 2 * Hpercell);
	putchar(192);			//goc trai duoi
	for (int i = x + 1; i <= x + Wpercell * 3; i++) {
		if (i == x + Wpercell * 3)
			putchar(217);		//goc phai duoi
		else if ((i - x) % Wpercell == 0)
			putchar(193);		//goc nga 3
		else
			putchar(196);		//bien ngang
	}

	Common::gotoXY(x + Wpercell + (Wpercell / 2), y + (Hpercell / 2));
	putchar(up);
	Common::gotoXY(x + (Wpercell / 2), y + Hpercell + (Hpercell / 2));
	putchar(right);
	Common::gotoXY(x + Wpercell + (Wpercell / 2), y + Hpercell + (Hpercell / 2));
	putchar(down);
	Common::gotoXY(x + Wpercell * 2 + (Wpercell / 2), y + Hpercell + (Hpercell / 2));
	putchar(left);

}

void drawRectangle(int x, int y, int length, int width) {
	Common::gotoXY(x, y);
	putchar(218);		//goc trai tren
	for (int i = x + 1; i <= x + length; i++) {
		if (i == x + length)
			putchar(191);	//goc phai tren
		else putchar(196);	//bien ngang
	}
	for (int k = 0; k <= 1; k++) {
		for (int i = y + 1; i < y + width; i++) {
			Common::gotoXY(x + k * length, i);
			putchar(179);	//bien doc
		}
	}
	Common::gotoXY(x, y + width);
	putchar(192);			//goc trai duoi
	for (int i = x + 1; i <= x + length; i++) {
		if (i == x + length)
			putchar(217);	//goc phai duoi
		else putchar(196);	//bien ngang
	}

}

void Tutorial2() {
Common:ShowCursor(false);

	Common::setFontInfo(10, 21);
	Common::gotoXY(32, 3);
	Common::setConsoleColor(BLACK, YELLOW);
	cout << "KEYBOARD CONTROLS";

	Common::setConsoleColor(BLACK, WHITE);
	Common::gotoXY(6, 6);
	cout << "USE THESE KEYS ON YOUR KEYBOARD TO MOVE: ";
	Common::gotoXY(38, 10);
	cout << "OR";

	drawKeyboardMove(15, 8, 2, 4, 'W', 'S', 'A', 'D');

	drawKeyboardMove(52, 8, 2, 4, '^', 'v', '<', '>');

	Common::gotoXY(6, 15);
	cout << "AND PRESS: ";
	drawRectangle(18, 14, 8, 2);
	Common::gotoXY(20, 15);
	cout << "ENTER";
	Common::gotoXY(30, 15);
	cout << "TO LOCK YOUR SELECTED CELL";

	Common::gotoXY(2, 19);
	cout << endl;

	//========Tao nut BACK NEXT HOME============
	Common::setConsoleColor(BLACK, PURPLE);
	char key;

	while (true) {
		Common::gotoXY(1, 1);
		putchar(60);
		putchar(205);
		cout << " BACK";

		Common::gotoXY(70, 1);
		cout << "NEXT ";
		putchar(205);
		putchar(62);

		Common::gotoXY(2, 18);
		cout << " HOME (ESC)";

		key = _getch();

		if (key == 75 || tolower(key) == 'a') {
			system("cls");
			Tutorial1();
			break;
		}
		if (key == 77 || tolower(key) == 'd') {
			system("cls");
			Tutorial3();
			break;
		}
		if (key == 27) {
			system("cls");
			Menu::mainMenu();
			break;
		}
	}
}

//=======TUTORIAL PAGE 3: VALID MATCHES=========
void printBoard(int x, int y, int row, int col, int W, int H) {
	for (int k = 0; k <= row; k++) {
		Common::gotoXY(x, y + k * H);
		if (k == 0) {
			putchar(201);	//goc trai tren
			for (int i = x + 1; i <= x + col * W; i++) {
				if (i == x + col * W)
					putchar(187);	//goc phai tren
				else if ((i - x) % W == 0)
					putchar(203);	//nga 3 up
				else putchar(205);	//=
			}
		}
		else if (k == row) {
			putchar(200);	//goc trai duoi
			for (int i = x + 1; i <= x + col * W; i++) {
				if (i == x + col * W)
					putchar(188);	//goc phai duoi
				else if ((i - x) % W == 0)
					putchar(202);	//nga 3 ngua
				else putchar(205);	//=
			}
		}
		else {
			putchar(204);	//nga 3 sang phai
			for (int i = x + 1; i <= x + col * W; i++) {
				if (i == x + col * W)
					putchar(185);	//nga 3 quay trai
				else if ((i - x) % W == 0)
					putchar(206);	//nga 4
				else putchar(205);	//=
			}
		}
	}
	for (int k = 0; k <= col; k++) {
		for (int i = y + 1; i < y + row * H; i++) {
			if ((i - y) % H != 0) {
				Common::gotoXY(x + k * W, i);
				putchar(186);	//cot doc
			}
		}
	}
}

void Imatch(int x, int y) {
	printBoard(x, y, 3, 4, 4, 2);
	char a[] = { 'C','D','F','A',
				'D',' ',' ','B',
				'A','C','F','B'
	};
	Common::gotoXY(x + 4 * 2, y + 2);
	putchar(202);		//nga 3 ngua
	Common::gotoXY(x + 4 * 2, y + 2 * 2);
	putchar(203);		//nga 3 up
	for (int i = 1; y + 2 + i < y + 2 * 2; i++) {
		Common::gotoXY(x + 4 * 2, y + 2 + i);
		putchar(' ');
	}
	//to mau o
	int index = 0;
	for (int i = y + 2 / 2; i <= y + 2 * 2 + 2 / 2; i += (2 / 2 + 1)) {
		for (int j = x + 4 / 2; j <= x + 4 * 3 + 4 / 2; j += (4 / 2 * 2)) {
			Common::gotoXY(j, i);
			if (a[index] == 'F' || a[index] == 'B') {
				Common::setConsoleColor(GREEN, BLACK);
			}
			else
				Common::setConsoleColor(BLACK, WHITE);
			putchar(a[index++]);

		}
	}

	//ke duong noi
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	for (int k = 2; k <= 2 * 2; k++) {
		Common::gotoXY(x + 4 * 2 + 4 / 2, y + k);
		putchar(179);
	}
	Common::gotoXY(x + 4 * 3 + 4 / 2, y + 2 * 2);
	putchar(179);
	Common::setConsoleColor(BLACK, WHITE);
}

void Lmatch(int x, int y) {
	printBoard(x, y, 3, 4, 4, 2);
	char a[] = { 'C',' ','F','A',
				'D',' ','B','D',
				'A','C','F','B'
	};

	Common::gotoXY(x + 4, y);
	putchar(187);		//goc phai tren
	Common::gotoXY(x + 4, y + 2);
	putchar(185);		//nga 3 sang trai
	Common::gotoXY(x + 4 * 2, y);
	putchar(201);		//goc trai tren
	Common::gotoXY(x + 4 * 2, y + 2);
	putchar(204);		//nga 3 sang phai

	for (int i = 0; i <= 1; i++) {
		for (int j = x + 4 + 1; j < x + 4 * 2; j++) {
			Common::gotoXY(j, y + 2 * i);
			putchar(' ');
		}
	}
	//to mau o
	int index = 0;
	for (int i = y + 2 / 2; i <= y + 2 * 2 + 2 / 2; i += (2 / 2 + 1)) {
		for (int j = x + 4 / 2; j <= x + 4 * 3 + 4 / 2; j += (4 / 2 * 2)) {
			Common::gotoXY(j, i);
			if (a[index] == 'C') {
				Common::setConsoleColor(GREEN, BLACK);
			}
			else
				Common::setConsoleColor(BLACK, WHITE);
			putchar(a[index++]);

		}
	}

	//ke duong noi
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	Common::gotoXY(x + 4, y + 2 / 2);
	putchar(196);
	putchar(196);
	Common::gotoXY(x + 4 + 4 / 2, y + 2 / 2);
	putchar(191);
	for (int k = 2; k <= 2 * 2; k++) {
		Common::gotoXY(x + 4 + 4 / 2, y + k);
		putchar(179);
	}

	Common::setConsoleColor(BLACK, WHITE);
}

void Umatch(int x, int y) {
	printBoard(x, y, 3, 4, 4, 2);
	char a[] = { 'C',' ','F',' ',
				'B',' ','C','D',
				'A','D','F','B'
	};

	Common::gotoXY(x + 4, y);
	putchar(187);		//goc phai tren
	Common::gotoXY(x + 4, y + 2);
	putchar(185);		//nga 3 sang trai
	Common::gotoXY(x + 4 * 2, y);
	putchar(201);		//goc trai tren
	Common::gotoXY(x + 4 * 2, y + 2);
	putchar(204);		//nga 3 sang phai

	Common::gotoXY(x + 4 * 4, y + 2);
	putchar(187);		//goc phai tren
	Common::gotoXY(x + 4 * 3, y);
	putchar(187);		//goc phai tren

	for (int i = 0; i <= 1; i++) {
		for (int j = x + 4 + 1; j < x + 4 * 2; j++) {
			Common::gotoXY(j, y + 2 * i);
			putchar(' ');
		}
	}
	for (int j = x + 4 * 3 + 1; j <= x + 4 * 4; j++) {
		Common::gotoXY(j, y);
		putchar(' ');
	}
	for (int i = y + 1; i < y + 2; i++) {
		Common::gotoXY(x + 4 * 4, i);
		putchar(' ');
	}

	//to mau o
	int index = 0;
	for (int i = y + 2 / 2; i <= y + 2 * 2 + 2 / 2; i += (2 / 2 + 1)) {
		for (int j = x + 4 / 2; j <= x + 4 * 3 + 4 / 2; j += (4 / 2 * 2)) {
			Common::gotoXY(j, i);
			if (a[index] == 'D') {
				Common::setConsoleColor(GREEN, BLACK);
			}
			else
				Common::setConsoleColor(BLACK, WHITE);
			putchar(a[index++]);

		}
	}

	//ke duong noi
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	for (int k = 2 * 2; k >= -1; k--) {
		Common::gotoXY(x + 4 + 4 / 2, y + k);
		if (k != -1)
			putchar(179);
		else
			putchar(218);
	}
	for (int k = x + 4 + 4 / 2 + 1; k <= x + 4 * 3 + 4 / 2; k++) {
		if (k == x + 4 * 3 + 4 / 2)
			putchar(191);
		else
			putchar(196);
	}
	for (int k = 0; k <= 2; k++) {
		Common::gotoXY(x + 4 * 3 + 4 / 2, y + k);
		putchar(179);
	}
	Common::setConsoleColor(BLACK, WHITE);
}

void Zmatch(int x, int y) {
	printBoard(x, y, 3, 4, 4, 2);
	char a[] = { ' ',' ','F','B',
				'C',' ','B','D',
				'F',' ',' D','C'
	};
	Common::gotoXY(x, y + 2);
	putchar(201);		//goc trai tren

	Common::gotoXY(x + 4, y + 2);
	putchar(187);		//goc phai tren
	Common::gotoXY(x + 4, y + 2 * 2);
	putchar(185);		//nga 3 sang trai
	Common::gotoXY(x + 4, y + 2 * 3);
	putchar(188);		//goc phai duoi

	Common::gotoXY(x + 4 * 2, y);
	putchar(201);		//goc trai tren
	Common::gotoXY(x + 4 * 2, y + 2);
	putchar(204);		//nga 3 sang phai
	Common::gotoXY(x + 4 * 2, y + 2 * 2);
	putchar(204);		//nga 3 sang phai
	Common::gotoXY(x + 4 * 2, y + 2 * 3);
	putchar(200);		//goc trai duoi

	for (int k = 0; k <= 3; k++) {
		if (k == 0)
			for (int j = x; j < x + 4 * 2; j++) {
				Common::gotoXY(j, y + 2 * k);
				putchar(' ');
			}
		else
			for (int j = x + 4 + 1; j < x + 4 * 2; j++) {
				Common::gotoXY(j, y + 2 * k);
				putchar(' ');
			}
	}
	for (int k = 0; k <= 1; k++) {
		for (int i = y + 1; i < y + 2; i++) {
			Common::gotoXY(x + k * 4, i);
			putchar(' ');
		}
	}
	//to mau o
	int index = 0;
	for (int i = y + 2 / 2; i <= y + 2 * 2 + 2 / 2; i += (2 / 2 + 1)) {
		for (int j = x + 4 / 2; j <= x + 4 * 3 + 4 / 2; j += (4 / 2 * 2)) {
			Common::gotoXY(j, i);
			if (a[index] == 'F') {
				Common::setConsoleColor(GREEN, BLACK);
			}
			else
				Common::setConsoleColor(BLACK, WHITE);
			putchar(a[index++]);

		}
	}

	//ke duong noi
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	Common::gotoXY(x + 4 * 2 - 4 / 2, y + 2 / 2);
	putchar(196);
	putchar(196);
	putchar(196);
	Common::gotoXY(x + 4, y + 2 * 2 + 2 / 2);
	putchar(196);
	putchar(196);
	for (int k = 2 / 2; k <= 2 * 2 + 2 / 2; k++) {
		Common::gotoXY(x + 4 + 4 / 2, y + k);
		if (k == 2 / 2)
			putchar(218);
		else if (k == 2 * 2 + 2 / 2)
			putchar(217);
		else
			putchar(179);
	}

	Common::setConsoleColor(BLACK, WHITE);
}

void Tutorial3() {
	Common::showCursor(false);

	Common::gotoXY(6, 3);
	Common::setConsoleColor(BLACK, WHITE);
	cout << "VALID MATCHES SHOULD BE FOLLOWED WITH THESE PATTERNS: ";

	Imatch(10, 5);
	Umatch(50, 5);
	Lmatch(10, 14);
	Zmatch(50, 14);

	//========Tao nut BACK NEXT HOME============
	Common::setConsoleColor(BLACK, PURPLE);
	char key;

	while (true) {
		Common::gotoXY(1, 1);
		putchar(60);
		putchar(205);
		cout << " BACK";

		Common::gotoXY(70, 1);
		cout << "NEXT ";
		putchar(205);
		putchar(62);

		Common::gotoXY(2, 22);
		cout << " HOME (ESC)";

		key = _getch();

		if (key == 75 || tolower(key) == 'a') {
			system("cls");
			Tutorial2();
			break;
		}
		if (key == 77 || tolower(key) == 'd') {
			system("cls");
			Tutorial4();
			break;
		}
		if (key == 27) {
			system("cls");
			Menu::mainMenu();
			break;
		}
	}
}

//=======TUTORIAL PAGE 4: SCORES AND OUTRO========
void Tutorial4() {
	Common::showCursor(false);
	Common::setFontInfo(10, 21);
	Common::setConsoleColor(BLACK, WHITE);

	Common::gotoXY(6, 5);
	cout << "EACH VALID PAIR MATCHES SUCCESSFULLY RESULTING IN AN INCREASE OF 100 SCORES.";

	Common::gotoXY(6, 7);
	cout << "DON'T WORRY IF YOU COULDN'T FIND A VALID PAIR.";
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	drawRectangle(54, 6, 5, 2);
	Common::gotoXY(55, 7);
	cout << "HELP";
	Common::setConsoleColor(BLACK, WHITE);

	Common::gotoXY(61, 7);
	cout << "WILL GIVE YOU A HINT.";

	Common::gotoXY(6, 9);
	cout << "BUT BY DOING SO, YOUR CURRENT SCORE WILL BE REDUCED BY 50.";

	Common::gotoXY(37, 13);
	Common::setConsoleColor(RED, YELLOW);
	cout << "ENJOY THE GAME!";


	Common::setConsoleColor(BLACK, WHITE);
	Common::gotoXY(25, 15);
	cout << "TRY TO FINISH IT WITHIN THE SHORTEST TIME.";
	Common::gotoXY(23, 17);
	cout << "REGISTER TO LEADERBOARD WITH THE HIGHEST RANK.";

	//========Tao nut BACK HOME============
	Common::setConsoleColor(BLACK, PURPLE);
	char key;

	while (true) {
		Common::gotoXY(1, 1);
		putchar(60);
		putchar(205);
		cout << " BACK";

		Common::gotoXY(72, 1);
		cout << " HOME (ESC)";

		key = _getch();

		if (key == 75 || tolower(key) == 'a') {
			system("cls");
			Tutorial3();
			break;
		}
		if (key == 27) {
			system("cls");
			Menu::mainMenu();
			break;
		}
	}
}