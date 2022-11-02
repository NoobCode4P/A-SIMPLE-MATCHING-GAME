#pragma once

#include "Menu.h"
#include "Common.h"
#include <fstream>
#include <string>
using namespace std;

struct Leaderboard {
	static void LeaderboardScreen();
	static void LeaderboardLogo();
	static void DrawBoardLeaderboard(); // vẽ khung leaderboard
	static void BackButton(); // button trở về main menu
	static void PrintInfoPlayer(); // Hiển thị thông tin người chơi
};