#include "Leaderboard.h"

void Leaderboard::LeaderboardScreen() {
	Common::clearConsole();
	LeaderboardLogo(); // Vẽ logo
	DrawBoardLeaderboard(); // Vẽ bảng
	PrintInfoPlayer();
	BackButton();
	while (true) {
		int key = Common::getConsoleInput();
		if (key == 1) { // ESC
			Common::playSound(3);
			Menu::mainMenu();
			break;
		}
	}
}

void Leaderboard::LeaderboardLogo() {

	Common::gotoXY(0, 0);

	cout << R"(
			    __    _________    ____  __________  ____  ____  ___    ____  ____ 
			   / /   / ____/   |  / __ \/ ____/ __ \/ __ )/ __ \/   |  / __ \/ __ \
			  / /   / __/ / /| | / / / / __/ / /_/ / __  / / / / /| | / /_/ / / / /
			 / /___/ /___/ ___ |/ /_/ / /___/ _, _/ /_/ / /_/ / ___ |/ _, _/ /_/ / 
			/_____/_____/_/  |_/_____/_____/_/ |_/_____/\____/_/  |_/_/ |_/_____/                                                                        
	)";
}

void Leaderboard::DrawBoardLeaderboard() {
	int verticalIndex[3] = { 10,60,80 }; // Vị trí x trên console của hàng kẻ dọc

	Common::drawBorder(10, 7, 100, 4, 1);
	Common::drawBorder(10, 11, 100, 3 * 7 + 1, 1);
	Common::gotoXY(10, 11);
	putchar(195);
	Common::gotoXY(110, 11);
	putchar(180);
	for (int i = 2; i < 27; i++) {
		for (int j = 0; j < 3; j++) {
			Common::gotoXY(10 + verticalIndex[j] - 1, 6 + i);
			putchar(179);
		}
	}

	Common::gotoXY(13, 9);
	cout << "RANK";
	Common::gotoXY(42, 9);
	cout << "NAME";
	Common::gotoXY(77, 9);
	cout << "SCORE";
	Common::gotoXY(98, 9);
	cout << "TIME";
}

void Leaderboard::BackButton() {
	Common::drawBorder(2, 1, 4, 2, 1);
	Common::gotoXY(4, 2);
	putchar(60);
	//cout << "ESC: BACK";
}

void Leaderboard::PrintInfoPlayer() {
	ifstream fs;
	fs.open("leaderboard.txt");

	struct Player {
		string name;
		int score;
		int time;
	};

	Player player[1000];
	string s;
	int size = 0;
	if (fs) {
		while (!fs.eof()) {
			getline(fs, player[size].name, '/');
			getline(fs, s, '/');
			player[size].score = stoi(s);
			getline(fs, s);
			player[size].time = stoi(s);
			size++;
		}

		for (int i = 0; i < size - 1; i++) {
			for (int j = i + 1; j < size; j++) {
				if (player[i].score < player[j].score) {
					swap(player[i], player[j]);
				}
				else if (player[i].score == player[j].score) {
					if (player[i].time > player[j].time) {
						swap(player[i], player[j]);
					}
				}
			}
		}

		for (int i = 0; i < min(7, size - 1); i++) {
			Common::gotoXY(14, 13 + i * 3);
			cout << i + 1;
			Common::gotoXY(24, 13 + i * 3);
			cout << player[i].name;
			Common::gotoXY(77, 13 + i * 3);
			cout << player[i].score;
			Common::gotoXY(99, 13 + i * 3);
			cout << player[i].time;
		}

		fs.close();
	}
	else {
		//cout << "Error opening file";
	}
}