#pragma once
#include "Board.h"
#include "Common.h"
#include "Menu.h"
#include <algorithm>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;

struct Game {
	int _x, _y; // Tọa độ x y của console
	pair<int, int> firstBlock; // Lock ô thứ nhất
	pair<int, int> secondBlock; // Lock ô thứ hai
	bool _isLoop; // true/ false: game chạy/ dừng
	bool _isEndGame; // Kiểm tra game kết thúc hay chưa
	bool _isPairValidExisted; // Kiểm tra còn cặp nào thỏa mãn hay không
	int _cntCellMatch; // Đếm xem đã xóa bao nhiêu character 
	int _cntEnter; // Biến enter
	bool _help; // Người chơi cần giúp đỡ
	int _time;// Thời gian chơi game
	int _score; // điểm của người chơi
	string _name; // Tên của người chơi
	Board* _b; // Tạo bảng game

	Game();
	~Game();

	void startGame(); // Bắt đầu game
	bool endGame(); // kiểm tra kết thúc game

	void moveUp(); // di chuyển lên trên
	void moveDown(); // di chuyển xuống
	void moveLeft(); // di chuyển sang trái
	void moveRight(); // di chuyển sang phải

	int checkIMatching(pair<int, int>, pair<int, int>);
	bool checkZMatching(pair<int, int>, pair<int, int>);
	bool checkUMatching(pair<int, int>, pair<int, int>);
	bool checkCharacterMatching(pair<int, int>, pair<int, int>); // Kiểm tra giá trị 2 char có bằng nhau
	bool checkMatching(pair<int, int>, pair<int, int>); // Kiểm tra 2 ô đó có match với nhau
	void solveMatching(); // Xử lý matching
	bool checkPairValidExisted(); // Kiểm tra xem còn cặp nào có thể matching được với nhau không 
	void printGameScreen(); // In các chi tiết của game ra console 
	void saveData(); // tạo leaderboard
};