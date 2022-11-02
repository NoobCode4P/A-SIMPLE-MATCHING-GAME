#pragma once
#include <iostream>

#include <cctype>
#include "Common.h"
#include "Game.h"
#include "GTutorial.h"
#include "Leaderboard.h"
#include <string>
using namespace std;

struct Menu {

	static string optionList[4];

	static void mainMenu();

	static void setupMainOption();
	static void drawLogo();
	static string inputName(); // Nhập tên người chơi

	static void GameTitle();
	static void PlayMode();
	static void Tutorial();
	static void endScreen(int, int); // Màn hình khi hoàn thành game
	static void ExitGame();
};