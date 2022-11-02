#include "Menu.h"

string Menu::optionList[] = { " PLAY", " HOW TO PLAY", " LEADERBOARD", " EXIT" };

void Menu::drawLogo() {
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	Common::gotoXY(27, 3);
	cout << "  __  __   _ _____ ___ _  _ ___ _  _  ___    ___   _   __  __ ___ ";
	Common::gotoXY(27, 4);
	cout << " |  \\/  | /_\\_   _/ __| || |_ _| \\| |/ __|  / __| /_\\ |  \\/  | __|";
	Common::gotoXY(27, 5);
	cout << " | |\\/| |/ _ \\| || (__| __ || || .` | (_ | | (_ |/ _ \\| |\\/| | _| ";
	Common::gotoXY(27, 6);
	cout << " |_|  |_/_/ \\_\\_| \\___|_||_|___|_|\\_|\\___|  \\___/_/ \\_\\_|  |_|___|";
}

void Menu::GameTitle() {
	drawLogo();
}

void Menu::PlayMode() {
	Common::gotoXY(43, 11);
	Common::setConsoleColor(0, 6);
	cout << "Play Mode";
}

void Menu::Tutorial() {
	Tutorial1();
}

void Menu::ExitGame() {
	system("cls");
	Common::showCursor(false);
	Common::setConsoleColor(BLACK, AQUA);

	//20 1

	Common::drawBorder(40, 13, 45, 8, 1);

	Common::gotoXY(54, 15);
	cout << "Exit Confirmation";

	Common::gotoXY(46, 17);
	cout << "Are you sure you want to quit game?";

	int textcolor[] = { RED,WHITE };
	char key;
	int CurPos = 1;

	while (true) {
		Common::gotoXY(54, 19);
		Common::setConsoleColor(0, textcolor[0]);
		cout << "YES";

		Common::gotoXY(68, 19);
		Common::setConsoleColor(0, textcolor[1]);
		cout << "NO";

		key = _getch();

		if ((key == 77 || tolower(key) == 'd') && CurPos == 1)	//RIGHT ARROW
			CurPos++;
		if ((key == 75 || tolower(key) == 'a') && CurPos == 2)	//LEFT ARROW
			CurPos--;

		if (key == '\r') {
			if (CurPos == 1) {
				Common::gotoXY(19, 30);
				cout << "THANK YOU FOR PLAYING OUR GAME! HAVE A NICE DAY!" << endl;
				exit(EXIT_SUCCESS);
			}
			if (CurPos == 2) {
				system("cls");
				mainMenu();
				break;
			}
		}
		textcolor[0] = WHITE;
		textcolor[1] = WHITE;

		if (CurPos == 1)
			textcolor[0] = RED;
		if (CurPos == 2)
			textcolor[1] = GREEN;

	}
}

void Menu::setupMainOption() {
	int setTextColor[] = { RED,YELLOW,YELLOW,YELLOW,YELLOW };
	char key;
	int pos = 1;

	Common::setConsoleColor(BLACK, YELLOW);
	Common::drawBorder(55, 25, 16, 2, 4);

	Common::showCursor(false);

	int Xfor1stOpt = 60;
	int Yfor1stOpt = 26;
	while (true) {
		Common::gotoXY(Xfor1stOpt, Yfor1stOpt);
		Common::setConsoleColor(BLACK, setTextColor[0]);

		cout << optionList[0];			//play

		Common::gotoXY(Xfor1stOpt - 3, Yfor1stOpt + 2);
		Common::setConsoleColor(BLACK, setTextColor[1]);

		cout << optionList[1];			//how to play

		Common::gotoXY(Xfor1stOpt - 3, Yfor1stOpt + 4);
		Common::setConsoleColor(BLACK, setTextColor[2]);

		cout << optionList[2];			//Leaderboard

		Common::gotoXY(Xfor1stOpt, Yfor1stOpt + 6);
		Common::setConsoleColor(BLACK, setTextColor[3]);

		cout << optionList[3];			//exit

		key = _getch();

		if ((key == 72 || tolower(key) == 'w') && (pos >= 1 && pos <= 4)) {
			if (pos > 1)
				pos--;
			else pos = 4;
			Common::playSound(2);
		}// UP ARROW
		if ((key == 80 || tolower(key) == 's') && (pos >= 1 && pos <= 4)) {
			if (pos < 4)
				pos++;
			else pos = 1;
			Common::playSound(2);
		}// DOWN ARROW
		if (key == '\r') {

			if (pos == 1) {
				Common::playSound(3);
				Game g;
				g.startGame();
				break;
			}
			if (pos == 2) {
				Common::playSound(3);
				system("cls");
				Tutorial();
				break;
			}
			if (pos == 3) {
				Common::playSound(3);
				Leaderboard::LeaderboardScreen();
				break;
			}
			if (pos == 4) {
				Common::playSound(3);
				ExitGame();
				break;
			}
		}
		setTextColor[0] = YELLOW;
		setTextColor[1] = YELLOW;
		setTextColor[2] = YELLOW;
		setTextColor[3] = YELLOW;

		if (pos == 1)
			setTextColor[0] = RED;
		if (pos == 2)
			setTextColor[1] = RED;
		if (pos == 3)
			setTextColor[2] = RED;
		if (pos == 4)
			setTextColor[3] = RED;
	}

}

void Menu::mainMenu() {
	Common::showCursor(false);
	Common::clearConsole();

	GameTitle();
	setupMainOption();
}

void Menu::endScreen(int score, int time) {
	Common::clearConsole();

	Common::playSound(6);

	// In chữ victory
	{
		Common::setConsoleColor(BLACK, LIGHT_GREEN);
		Common::gotoXY(25, 10);
		cout << "      (`-.                     .-') _                _  .-')               ";
		Common::gotoXY(25, 11);
		cout << "    _(OO  )_                  (  OO) )              ( \\( -O )              ";
		Common::gotoXY(25, 12);
		cout << ",--(_/   ,. \\ ,-.-')   .-----./     '._  .-'),-----. ,------.   ,--.   ,--.";
		Common::gotoXY(25, 13);
		cout << "\\   \\   /(__/ |  |OO) '  .--./|'--...__)( OO'  .-.  '|   /`. '   \\  `.'  / ";
		Common::gotoXY(25, 14);
		cout << " \\   \\ /   /  |  |  \\ |  |('-.'--.  .--'/   |  | |  ||  /  | | .-')     /  ";
		Common::gotoXY(25, 15);
		cout << "  \\   '   /,  |  |(_//_) |OO  )  |  |   \\_) |  |\\|  ||  |_.' |(OO  \\   /   ";
		Common::gotoXY(25, 16);
		cout << "   \\     /__),|  |_.'||  |`-'|   |  |     \\ |  | |  ||  .  '.' |   /  /\\_  ";
		Common::gotoXY(25, 17);
		cout << "    \\   /   (_|  |  (_'  '--'\\   |  |      `'  '-'  '|  |\\  \\  `-./  /.__) ";
		Common::gotoXY(25, 18);
		cout << "     `-'      `--'     `-----'   `--'        `-----' `--' '--'   `--'      ";
	} // In chữ victory

	Common::drawBorder(35, 21, 18, 4, 1);
	Common::gotoXY(39, 23);
	cout << "SCORE: " << score;

	Common::drawBorder(70, 21, 18, 4, 1);
	Common::gotoXY(75, 23);
	cout << "TIME: " << time;

	Sleep(8000);

	Menu::mainMenu();

	/*Common::drawBorder(55, 30, 12, 2, 1);
	Common::gotoXY(59, 31);
	cout << "ENTER";

	while (true) {
		int ch = Common::getConsoleInput();
		if (ch == 6) {
			Menu::mainMenu();
			break;
		}
	}*/
}

string Menu::inputName() {
	Common::clearConsole();

	GameTitle();

	Common::gotoXY(50, 20);
	string s;
	cout << "YOUR NAME: ";
	getline(cin, s);
	return s;
}