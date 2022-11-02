#pragma once
#include <iostream>
#include <Windows.h>
#include "Common.h"
#include <vector>
#include <fstream>
using namespace std;

struct Board {
	int _size; // Size của bảng game, size x size
	char** _A; // Mảng 2 chiều lưu các characters
	bool** _LOCK; // Kiểm tra xem phần tử ở mảng A đã lock hay chưa
	int _cellRow; // ĐỘ CAO 1 Ô
	int _cellCol; // ĐỘ DÀI 1 Ô
	char** _background; // Mảng chứa background của hình

	Board(int); // Constructor khởi tạo Board
	~Board(); // Destructor 

	void drawBoard(); // Vẽ bảng game
	void cellColor(int, int, int, int); // Hiển thị màu ở ô với background + màu chữ
	void randomCharacter(); // Random character
	void printCharacter(); // In mảng character đã random ra console 
	int getCellRow(); // Lấy độ cao 1 ô
	int getCellCol(); // lấy độ dài 1 ô
	int getSize(); // lấy giá trị size
	char getCharacterByXY(int, int); // Lấy ký tự tại ô có vị trí x y trên console 
	char getCharacterByIJ(int, int); // lấy ký tự tại ô có vị trí i j trên bảng
	void setCharacterByIJ(int, int); // Thay đổi ký tự ô có vị trí i j thành '0' ( đã xóa)
	int getXInConsole(int); // Lấy vị trí X trên console của character 
	int getYInConsole(int); // Lấy vị trí Y trên console của character
	int getIByYConsole(int); // Lấy index i trên bảng từ vị trí Y trên console 
	int getJByXConsole(int); // Lấy index i trên bảng từ vị trí X trên console 
	bool isCharacterLocked(int, int); // Kiểm tra xem ô này đã bị lock hay chưa
	void setCharacterLocked(int, int); // Gán giá trị cho _Lock[i][j]
	void deleteCellInConsoleWhenMatched(int, int); // Xóa ô trên console khi match
	void showBackgroundConsoleWhenMatched(int, int); // Hiện background khi xóa cell
	void printScoreBoard(); // Hiển thị bảng điểm và chi tiết game
	void printButton(); // Hiển thị các nút thao tác game
	void getBackground(); // Lấy background từ txt
};