#include "Board.h"

Board::Board(int size) {
	_size = size; // Khởi tạo size
	_cellRow = 5;
	_cellCol = 9;

	// Khởi tạo mảng characters
	_A = new char* [_size + 2];
	_LOCK = new bool* [_size + 2];
	for (int i = 0; i <= _size + 1; i++) {
		_A[i] = new char[_size + 2];
		_LOCK[i] = new bool[_size + 2];
	}

	for (int i = 0; i <= _size + 1; i++) {
		for (int j = 0; j <= _size + 1; j++) {
			_A[i][j] = '0';
			_LOCK[i][j] = false;
		}
	}

	// Khởi tạo mảng background
	_background = new char* [27];
	for (int i = 1; i <= 26; i++) {
		_background[i] = new char[53];
	}

	getBackground();
}

Board::~Board()
{
	for (int i = 0; i <= _size + 1; i++) {
		delete[] _A[i];
	}
	delete[] _A;
}

void Board::randomCharacter() {
	// Tạo mảng character 
	vector<char> Alphabet;
	vector<bool> lockAlphabet; // Kiểm tra đã đưa vị trí này vào bảng game hay chưa
	int i = 65;
	int cnt = 2;
	while (cnt <= _size * _size) {
		Alphabet.push_back(char(i));
		Alphabet.push_back(char(i));
		lockAlphabet.push_back(false);
		lockAlphabet.push_back(false);
		i++;
		if (i > 65+11) i = 65;
		cnt += 2;
	}

	// Thực hiện random vị trí
	for (int i = 1; i <= _size; i++) {
		for (int j = 1; j <= _size; j++) {
			int randomPos = rand() % Alphabet.size();
			while (lockAlphabet[randomPos] == true) {
				randomPos = rand() % Alphabet.size();
			}
			lockAlphabet[randomPos] = true;
			_A[i][j] = Alphabet[randomPos];
		}
	}
}

void Board::printCharacter() {
	// Phần tử đầu tiên bắt đầu tại vị trí x = 5, y = 3
	for (int i = 1; i <= _size; i++) {
		for (int j = 1; j <= _size; j++) {
			int x = getXInConsole(j);
			int y = getYInConsole(i);
			Common::gotoXY(x, y); // chuyển con trỏ console tới vị trí x y
			cout << _A[i][j]; // in character ra console 
		}
	}
}

void Board::drawBoard() {
	int COLUMN = 8 * _size + 1; // ĐỘ DÀI BẢNG
	int ROW = 4 * _size + 1; // ĐỘ CAO BẢNG

	// Tao bien tren cua bang
	Common::gotoXY(1, 1);
	putchar(201); // Góc trái trên
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, 1);
		if ((i - 1) % (_cellCol - 1) == 0) {
			putchar(203);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, 1);
	putchar(187); // góc phải trên

	// Tao bien duoi cua bang
	Common::gotoXY(1, ROW);
	putchar(200); // góc trái dưới
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(i, ROW);
		if ((i - 1) % (_cellCol - 1) == 0) {
			putchar(202);
		}
		else {
			putchar(205);
		}
	}
	Common::gotoXY(COLUMN, ROW);
	putchar(188); // góc phải dưới

	//Tao bien trai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(1, i);
		if ((i - 1) % (_cellRow - 1) == 0) {
			putchar(204);
		}
		else {
			putchar(186);
		}
	}

	//Tao bien phai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(COLUMN, i);
		if ((i - 1) % (_cellRow - 1) == 0) {
			putchar(185);
		}
		else {
			putchar(186);
		}
	}

	// VE BANG THEO CHIEU NGANG

	for (int j = 2; j < COLUMN; j++) {
		int i = 5;
		while (i < ROW) {
			Common::gotoXY(j, i);
			if ((j - 1) % (_cellCol - 1) == 0) {
				putchar(206);
			}
			else {
				putchar(205);
			}
			i += 4;
		}
		Sleep(10);
	}

	// VE BANG THEO CHIEU DOC

	for (int j = 2; j < ROW; j++) {
		int i = 9;
		while (i < COLUMN) {
			Common::gotoXY(i, j);
			if ((j - 1) % (_cellRow - 1) == 0) {
				putchar(206);
			}
			else {
				putchar(186);
			}
			i += 8;
		}
		Sleep(20);
	}
}

void Board::cellColor(int x, int y, int background, int fontColor) {
	Common::setConsoleColor(background, fontColor);
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 3; j <= x + 3; j++) {
			Common::gotoXY(j, i);
			putchar(32);
		}
	}
	Common::gotoXY(x, y);
	cout << getCharacterByXY(x, y);
	Common::gotoXY(x, y);
}

int Board::getCellCol() {
	return _cellCol;
}

int Board::getCellRow() {
	return _cellRow;
}

int Board::getSize() {
	return _size;
}

int Board::getXInConsole(int j) {
	return 5 + (j - 1) * (_cellCol - 1);
}

int Board::getYInConsole(int i) {
	return 3 + (i - 1) * (_cellRow - 1);
}

int Board::getIByYConsole(int y) {
	return (((y - 3) / (_cellRow - 1)) + 1);
}

int Board::getJByXConsole(int x) {
	return (((x - 5) / (_cellCol - 1)) + 1);
}

char Board::getCharacterByXY(int x, int y) {
	int i = getIByYConsole(y);
	int j = getJByXConsole(x);
	return _A[i][j];
}

char Board::getCharacterByIJ(int i, int j) {
	return _A[i][j];
}

void Board::setCharacterByIJ(int i, int j) {
	_A[i][j] = '0';
}

bool Board::isCharacterLocked(int i, int j) {
	return _LOCK[i][j];
}

void Board::setCharacterLocked(int i, int j) {
	_LOCK[i][j] = 1 - _LOCK[i][j];
}

void Board::deleteCellInConsoleWhenMatched(int i, int j) {
	// góc trái trên
	if (_A[i - 1][j] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(200);
	}

	if (_A[i - 1][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(188);
	}

	if (_A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(187);
	}

	if (_A[i - 1][j] != '0' && _A[i - 1][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(202);
	}

	if (_A[i - 1][j - 1] != '0' && _A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(185);
	}

	if (_A[i - 1][j] != '0' && _A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(206);
	}

	if (_A[i - 1][j - 1] == '0' && _A[i][j - 1] == '0' && _A[i - 1][j] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) - 2);
		putchar(32);
	}
	// góc phải trên
	if (_A[i - 1][j] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(188);
	}

	if (_A[i - 1][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(200);
	}

	if (_A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(201);
	}

	if (_A[i - 1][j] != '0' && _A[i - 1][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(202);
	}

	if (_A[i - 1][j + 1] != '0' && _A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(204);
	}

	if (_A[i - 1][j] != '0' && _A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(206);
	}

	if (_A[i - 1][j] == '0' && _A[i][j + 1] == '0' && _A[i - 1][j + 1] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) - 2);
		putchar(32);
	}
	// góc trái dưới
	if (_A[i + 1][j] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(201);
	}

	if (_A[i + 1][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(187);
	}

	if (_A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(188);
	}

	if (_A[i + 1][j] != '0' && _A[i + 1][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(203);
	}

	if (_A[i + 1][j - 1] != '0' && _A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(185);
	}

	if (_A[i + 1][j] != '0' && _A[i][j - 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(206);
	}

	if (_A[i + 1][j - 1] == '0' && _A[i][j - 1] == '0' && _A[i + 1][j] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + 2);
		putchar(32);
	}
	// góc phải dưới
	if (_A[i + 1][j] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(187);
	}

	if (_A[i + 1][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(201);
	}

	if (_A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(200);
	}

	if (_A[i + 1][j] != '0' && _A[i + 1][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(203);
	}

	if (_A[i + 1][j + 1] != '0' && _A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(204);
	}

	if (_A[i + 1][j] != '0' && _A[i][j + 1] != '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(206);
	}

	if (_A[i + 1][j + 1] == '0' && _A[i][j + 1] == '0' && _A[i + 1][j] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + 2);
		putchar(32);
	}
	// biên trên
	if (_A[i - 1][j] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		for (int k = -3; k <= 3; k++) {
			Common::gotoXY(getXInConsole(j) + k, getYInConsole(i) - 2);
			putchar(32);
		}
	}
	// biên trái
	if (_A[i][j - 1] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		for (int k = -1; k <= 1; k++) {
			Common::gotoXY(getXInConsole(j) - 4, getYInConsole(i) + k);
			putchar(32);
		}
	}
	// biên phải
	if (_A[i][j + 1] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		for (int k = -1; k <= 1; k++) {
			Common::gotoXY(getXInConsole(j) + 4, getYInConsole(i) + k);
			putchar(32);
		}
	}
	// biên dưới
	if (_A[i + 1][j] == '0') {
		Common::setConsoleColor(BLACK, BLACK);
		for (int k = -3; k <= 3; k++) {
			Common::gotoXY(getXInConsole(j) + k, getYInConsole(i) + 2);
			putchar(32);
		}
	}
}

void Board::printScoreBoard() {
	int STARTX = 70;
	int COLUMN = 41; // ĐỘ DÀI BẢNG
	int ROW = 4 * _size + 1;; // ĐỘ CAO BẢNG

	// Tao bien tren cua bang
	Common::gotoXY(STARTX, 1);
	putchar(201); // Góc trái trên
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(STARTX + i - 1, 1);
		putchar(205);
	}
	Common::gotoXY(COLUMN + STARTX - 1, 1);
	putchar(187); // góc phải trên

	// Tao bien duoi cua bang
	Common::gotoXY(STARTX, ROW);
	putchar(200); // góc trái dưới
	for (int i = 2; i < COLUMN; i++) {
		Common::gotoXY(STARTX + i - 1, ROW);
		putchar(205);
	}
	Common::gotoXY(COLUMN + STARTX - 1, ROW);
	putchar(188); // góc phải dưới

	//Tao bien trai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(STARTX, i);
		putchar(186);
	}

	//Tao bien phai cua bang
	for (int i = 2; i < ROW; i++) {
		Common::gotoXY(COLUMN + STARTX - 1, i);
		putchar(186);
	}

	Common::gotoXY(STARTX + 17, 5);
	cout << "SCORE";

	Common::gotoXY(STARTX + 17, 8);
	cout << "00000";
}

void Board::printButton() {
	Common::setConsoleColor(BLACK, LIGHT_AQUA);
	// Help button
	Common::drawBorder(70, 29, 16, 2, 1);
	Common::gotoXY(75, 30);
	cout << "H: HELP";

	// Exit button
	Common::drawBorder(94, 29, 16, 2, 1);
	Common::gotoXY(98, 30);
	cout << "ESC: EXIT";
}

void Board::getBackground() {
	fstream fs;
	fs.open("background.txt");

	int size = 0;
	string s;

	while (!fs.eof()) {
		size++;
		s = "";
		getline(fs, s);
		while (s.size() <= 48) {
			s += ' ';
		}
		for (int i = 0; i < s.size(); i++) {
			_background[size][i + 1] = s[i];
		}
	}

	while (size <= 23) {
		size++;
		s = "";
		while (s.size() <= 48) {
			s += ' ';
		}
		for (int i = 0; i < s.size(); i++) {
			_background[size][i + 1] = s[i];
		}
	}

	fs.close();
}

void Board::showBackgroundConsoleWhenMatched(int i, int j) {
	int x = getXInConsole(j);
	int y = getYInConsole(i);


	// Biên trên
	if (_A[i - 1][j] == '0') {
		for (int h = x - 3; h <= x + 3; h++) {
			Common::gotoXY(h, y - 2);
			Common::setConsoleColor(BLACK, WHITE);
			cout << _background[y - 2][h];
		}
	}

	// Biên dưới
	if (_A[i + 1][j] == '0') {
		for (int h = x - 3; h <= x + 3; h++) {
			Common::gotoXY(h, y + 2);
			Common::setConsoleColor(BLACK, WHITE);
			cout << _background[y + 2][h];
		}
	}

	// Biên trái
	if (_A[i][j - 1] == '0') {
		for (int h = y - 1; h <= y + 1; h++) {
			Common::gotoXY(x - 4, h);
			Common::setConsoleColor(BLACK, WHITE);
			cout << _background[h][x - 4];
		}
	}

	// Biên phải
	if (_A[i][j + 1] == '0') {
		for (int h = y - 1; h <= y + 1; h++) {
			Common::gotoXY(x + 4, h);
			Common::setConsoleColor(BLACK, WHITE);
			cout << _background[h][x + 4];
		}
	}

	// góc trái trên
	if (_A[i - 1][j] == '0' && _A[i - 1][j - 1] == '0' && _A[i][j - 1] == '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(x - 4, y - 2);
		cout << _background[y - 2][x - 4];
	}

	// góc phải trên
	if (_A[i - 1][j] == '0' && _A[i - 1][j + 1] == '0' && _A[i][j + 1] == '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(x + 4, y - 2);
		cout << _background[y - 2][x + 4];
	}

	// góc trái dưới
	if (_A[i + 1][j] == '0' && _A[i + 1][j - 1] == '0' && _A[i][j - 1] == '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(x - 4, y + 2);
		cout << _background[y + 2][x - 4];
	}

	// góc phải dưới
	if (_A[i + 1][j] == '0' && _A[i + 1][j + 1] == '0' && _A[i][j + 1] == '0') {
		Common::setConsoleColor(BLACK, WHITE);
		Common::gotoXY(x + 4, y + 2);
		cout << _background[y + 2][x + 4];
	}

	for (int h = y - 1; h <= y + 1; h++) {
		for (int k = x - 3; k <= x + 3; k++) {
			Common::gotoXY(k, h);
			Common::setConsoleColor(BLACK, WHITE);
			cout << _background[h][k];
		}
	}
}