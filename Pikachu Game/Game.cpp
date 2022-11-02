#include "Game.h"

Game::Game() {
	_x = 5; //  vị trí bắt đầu x = 5
	_y = 3; // vi trí bắt đầu y = 3
	_cntEnter = 0;
	_cntCellMatch = 0; // chưa xóa character nào
	_isPairValidExisted = true;
	_isEndGame = false;
	_isLoop = true; // Game đang chạy
	_help = false;
	_score = 0; // Điểm ban đầu = 0
	_time = time(0); // Bắt đầu tính thời gian
	_name = Menu::inputName(); // Nhập tên
	_b = new Board(6); // Tạo bảng game size = 6
}

Game::~Game() {
	delete _b;
	_b = nullptr;
}

void Game::startGame() {
	//Menu::inputName();
	printGameScreen(); // In các chi tiết game ra màn hình

	// Focus vào phần tử đầu
	Common::gotoXY(5, 3);
	_b->cellColor(_x, _y, WHITE, BLACK);

	while (_isLoop) {
		if (endGame() == true) {
			break;
		}

		switch (Common::getConsoleInput())
		{
		case 1: // ESC
			Common::clearConsole();
			_isLoop = false;
			Common::setConsoleColor(BLACK, WHITE);
			Menu::mainMenu();
			break;
		case 2:
			moveUp();
			break;
		case 3:
			moveLeft();
			break;
		case 4:
			moveRight();
			break;
		case 5:
			moveDown();
			break;
		case 6: // Enter
			solveMatching();
			break;
		case 7: // Need help
			_help = true;
			checkPairValidExisted();
			_help = false;
			break;
		default:
			break;
		}
	}
}

void Game::moveUp() {
	int posY = _y - _b->getCellRow() + 1;
	if (posY >= 3) {
		Common::playSound(2);
		if (_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == true) {
			_b->cellColor(_x, _y, BLUE, WHITE);
		}
		else if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->showBackgroundConsoleWhenMatched(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		}
		else {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->cellColor(_x, _y, WHITE, WHITE);
		}
		else {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}

	}
}

void Game::moveDown() {
	int posY = _y + _b->getCellRow() - 1;
	if (posY <= 3 + (_b->getSize() - 1) * (_b->getCellRow() - 1)) {
		Common::playSound(2);
		if (_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == true) {
			_b->cellColor(_x, _y, BLUE, WHITE);
		}
		else if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->showBackgroundConsoleWhenMatched(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		}
		else {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_y = posY;
		Common::gotoXY(_x, _y);
		if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->cellColor(_x, _y, WHITE, WHITE);
		}
		else {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

void Game::moveLeft() {
	int posX = _x - _b->getCellCol() + 1;
	if (posX >= 5) {
		Common::playSound(2);
		if (_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == true) {
			_b->cellColor(_x, _y, BLUE, WHITE);
		}
		else if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->showBackgroundConsoleWhenMatched(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		}
		else {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->cellColor(_x, _y, WHITE, WHITE);
		}
		else {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

void Game::moveRight() {
	int posX = _x + _b->getCellCol() - 1;
	if (posX <= 5 + (_b->getSize() - 1) * (_b->getCellCol() - 1)) {
		Common::playSound(2);
		if (_b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == true) {
			_b->cellColor(_x, _y, BLUE, WHITE);
		}
		else if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->showBackgroundConsoleWhenMatched(_b->getIByYConsole(_y), _b->getJByXConsole(_x));
		}
		else {
			_b->cellColor(_x, _y, BLACK, WHITE);
		}
		_x = posX;
		Common::gotoXY(_x, _y);
		if (_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0') {
			_b->cellColor(_x, _y, WHITE, WHITE);
		}
		else {
			_b->cellColor(_x, _y, WHITE, BLACK);
		}
	}
}

int Game::checkIMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	if (iA == iB && jA == jB) return 2; // 2 điểm là một

	// Không cùng hàng hoặc cột
	if ((iA != iB) && (jA != jB)) {
		return 0;
	}

	// Kiểm tra hàng dọc
	if (jA == jB) {
		if (iA > iB) {
			swap(iA, iB);
		}
		for (int i = iA + 1; i < iB; i++) {
			if (_b->getCharacterByIJ(i, jA) != '0') {
				return 0;
			}
		}
		if ((_b->getCharacterByIJ(iA, jA) == '0')
			|| (_b->getCharacterByIJ(iB, jB) == '0')) {
			return 2;
		}
		if (checkCharacterMatching(firstBlock, secondBlock) == true) {
			return 1;
		}
	}

	// Kiểm tra hàng ngang
	if (iA == iB) {
		if (jA > jB) {
			swap(jA, jB);
		}
		for (int i = jA + 1; i < jB; i++) {
			if (_b->getCharacterByIJ(iA, i) != '0') {
				return 0;
			}
		}
		if ((_b->getCharacterByIJ(iA, jA) == '0')
			|| (_b->getCharacterByIJ(iB, jB) == '0')) {
			return 2;
		}
		if (checkCharacterMatching(firstBlock, secondBlock) == true) {
			return 1;
		}
	}
	return 0;
}

bool Game::checkZMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	// Duyệt theo chiều ngang dọc ngang
	// điểm 1 nằm bên trái, điểm 2 nằm bên phải
	if (firstBlock.second > secondBlock.second) {
		swap(firstBlock, secondBlock);
	}

	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	for (int i = jA; i <= jB; i++) {
		pair<int, int> break1(iA, i);
		pair<int, int> break2(iB, i);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	// Duyệt theo chiều dọc ngang dọc
	// Điểm 1 nằm ở trên, điểm 2 nằm ở dưới
	if (firstBlock.first > secondBlock.first) {
		swap(firstBlock, secondBlock);
	}

	iA = firstBlock.first;
	jA = firstBlock.second;
	iB = secondBlock.first;
	jB = secondBlock.second;

	for (int i = iA; i <= iB; i++) {
		pair<int, int> break1(i, jA);
		pair<int, int> break2(i, jB);
		bool line1 = checkIMatching(firstBlock, break1);
		bool line2 = checkIMatching(break1, break2);
		bool line3 = checkIMatching(break2, secondBlock);

		if (line1 && line2 && line3) return true;
	}

	return false;
}

bool Game::checkUMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	// Duyệt theo chiều ngang dọc ngang
	int iA = firstBlock.first;
	int jA = firstBlock.second;
	int iB = secondBlock.first;
	int jB = secondBlock.second;

	for (int i = 0; i <= _b->getSize() + 1; i++) {
		pair<int, int> break1(iA, i);
		pair<int, int> break2(iB, i);
		int line1 = checkIMatching(firstBlock, break1);
		int line2 = checkIMatching(break1, break2);
		int line3 = checkIMatching(break2, secondBlock);

		if (line1 == 2 && line2 == 2 && line3 == 2) return true;
	}

	// Duyệt theo chiều dọc ngang dọc
	iA = firstBlock.first;
	jA = firstBlock.second;
	iB = secondBlock.first;
	jB = secondBlock.second;

	for (int i = 0; i <= _b->getSize() + 1; i++) {
		pair<int, int> break1(i, jA);
		pair<int, int> break2(i, jB);
		int line1 = checkIMatching(firstBlock, break1);
		int line2 = checkIMatching(break1, break2);
		int line3 = checkIMatching(break2, secondBlock);

		if (line1 == 2 && line2 == 2 && line3 == 2) return true;
	}

	return false;
}

bool Game::checkCharacterMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	int xa = firstBlock.first;
	int ya = firstBlock.second;
	int xb = secondBlock.first;
	int yb = secondBlock.second;
	char firstChar = _b->getCharacterByIJ(xa, ya); // Giá trị block 1
	char secondChar = _b->getCharacterByIJ(xb, yb); // Giá trị block 2

	if ((firstChar == secondChar) && (firstChar != '0') && (secondChar != '0')) {
		return true;
	}
	return false;
}

bool Game::checkMatching(pair<int, int> firstBlock, pair<int, int> secondBlock) {
	// Giá trị của 2 ô khác nhau thì false
	if (checkCharacterMatching(firstBlock, secondBlock) == false) {
		return false;
	}

	// Kiểm tra xem 2 ô đó có trùng vị trí hay không
	if (firstBlock.first == secondBlock.first && firstBlock.second == secondBlock.second) {
		return false;
	}

	return checkIMatching(firstBlock, secondBlock) || checkUMatching(firstBlock, secondBlock);
}

void Game::solveMatching() {
	// Ô đã xóa hoặc lock rồi thì không enter được nữa
	if ((_b->getCharacterByIJ(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == '0')
		|| _b->isCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)) == true)
	{
		return;
	}

	_cntEnter++;
	if (_cntEnter == 1) {
		_b->setCharacterLocked(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lock ô thứ 1
		firstBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lưu index ô thứ 1
		_b->cellColor(_x, _y, BLUE, WHITE); // Hiện màu đã chọn ô thứ 1
	}
	else {
		int iA = firstBlock.first; // i của ô 1
		int jA = firstBlock.second; // j của ô 1
		secondBlock = make_pair(_b->getIByYConsole(_y), _b->getJByXConsole(_x)); // Lưu index ô thứ 2
		int iB = secondBlock.first; // i của ô 2
		int jB = secondBlock.second; // j của ô 2

		// ô 1 và ô 2 match với nhau
		if (checkMatching(firstBlock, secondBlock) == true) {
			Common::playSound(3);
			_score += 100; // Cộng 100 điểm khi match thành công

			_cntCellMatch += 2; //  Đã xóa được thêm 2 ô
			_b->setCharacterByIJ(iA, jA); // xóa ô 1 trong bảng
			_b->setCharacterByIJ(iB, jB); // xóa ô 2 trong mảng

			_b->deleteCellInConsoleWhenMatched(firstBlock.first, firstBlock.second);
			_b->deleteCellInConsoleWhenMatched(secondBlock.first, secondBlock.second);

			_isPairValidExisted = checkPairValidExisted(); // Kiểm tra xem còn cặp hợp lệ ko

			// Màu xanh lá báo 2 ô match thành công
			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), GREEN, GREEN);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), GREEN, GREEN);

			Sleep(200);

			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLACK, BLACK);
			
			_b->showBackgroundConsoleWhenMatched(firstBlock.first, firstBlock.second);
			_b->showBackgroundConsoleWhenMatched(secondBlock.first, secondBlock.second);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), WHITE, WHITE);


			string s = to_string(_score);
			while (s.size() < 5) {
				s = '0' + s;
			}
			Common::gotoXY(70 + 17, 8);
			Common::setConsoleColor(BLACK, WHITE);
			cout << s;
		}
		else { // Nếu 2 ô không match với nhau
			Common::playSound(4);

			// Màu đỏ báo 2 ô không match được
			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), RED, WHITE);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), RED, WHITE);

			Sleep(200);

			// reset lại màu
			// Tô lại màu cho ô 1
			Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
			_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLACK, WHITE);

			// Tô lại màu cho ô 2
			Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
			_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), WHITE, BLACK);
		}

		// Bỏ lock ô 1
		_b->setCharacterLocked(iA, jA);

		// reset biến count
		_cntEnter = 0;
	}
}

bool Game::checkPairValidExisted() {
	for (int iA = 1; iA <= _b->getSize(); iA++) {
		for (int jA = 1; jA <= _b->getSize(); jA++) {
			pair<int, int> firstBlock(iA, jA);
			for (int iB = 1; iB <= _b->getSize(); iB++) {
				for (int jB = 1; jB <= _b->getSize(); jB++) {
					pair<int, int> secondBlock(iB, jB);
					if (checkMatching(firstBlock, secondBlock) == true) {
						if (_help == true) {
							_score = max(0, _score - 50); // Sử dụng help thì mất 50 điểm

							int x = _x;
							int y = _y;

							// Tô lại màu cho ô 1
							Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
							_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), PURPLE, WHITE);

							// Tô lại màu cho ô 2
							Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
							_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), PURPLE, WHITE);

							Sleep(200);

							// Tô lại màu cho ô 1
							if (_b->isCharacterLocked(iA, jA) == true) {
								Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
								_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLUE, WHITE);
							}
							else {
								Common::gotoXY(_b->getXInConsole(jA), _b->getYInConsole(iA));
								_b->cellColor(_b->getXInConsole(jA), _b->getYInConsole(iA), BLACK, WHITE);
							}

							// Tô lại màu cho ô 2
							if (_b->isCharacterLocked(iB, jB) == true) {
								Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
								_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), BLUE, WHITE);
							}
							else {
								Common::gotoXY(_b->getXInConsole(jB), _b->getYInConsole(iB));
								_b->cellColor(_b->getXInConsole(jB), _b->getYInConsole(iB), BLACK, WHITE);
							}

							if (_b->getCharacterByXY(x, y) == '0') {
								Common::gotoXY(x, y);
								_b->cellColor(x, y, WHITE, WHITE);
							}
							else {
								Common::gotoXY(x, y);
								_b->cellColor(x, y, WHITE, BLACK);
							}

							string s = to_string(_score);
							while (s.size() < 5) {
								s = '0' + s;
							}
							Common::gotoXY(70 + 17, 8);
							Common::setConsoleColor(BLACK, WHITE);
							cout << s;
						}
						return true;
					}
				}
			}
		}
	}

	return false;
}

bool Game::endGame() {
	_isEndGame = (_cntCellMatch == _b->getSize() * _b->getSize())
		|| (_isPairValidExisted == false);
	if (_isEndGame == true) {
		_isLoop = false;
		_time = time(0) - _time;
		saveData();
		Sleep(300);
		Menu::endScreen(_score, _time);
	}

	return _isEndGame;
}

void Game::printGameScreen() {
	Common::clearConsole();
	Common::setConsoleColor(BLACK, WHITE);
	_b->drawBoard(); // vẽ bảng
	_b->randomCharacter(); // random mảng
	_b->printCharacter(); // in character trong mảng ra console 
	_b->printScoreBoard(); // In bảng điểm ra console
	_b->printButton();
}

void Game::saveData() {
	fstream fs("leaderboard.txt", ios::app);
	if (fs) {
		fs << _name << "/" << _score << "/" << _time << '\n';
	}
	else {
		cout << "Error opening file";
	}
	fs.close();
}