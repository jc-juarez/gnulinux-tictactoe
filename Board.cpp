#include <iostream>
#include <vector>
#include <utility>
#include "Board.h"

TicTacToe::Board::Board(int _size) {
	size = _size;
	winner = 0;
	for (int i = 0; i < size; i++) {
		rows.push_back({ true,{0,0} });
		cols.push_back({ true,{0,0} });
		std::vector<int> temp(size, 0);
		memory.push_back(temp);
	}
	diag1 = { true, {0,0} };
	diag2 = { true, {0,0} };
}

void TicTacToe::displayBoard(TicTacToe::Board &board) {
	std::cout << "\n\n";
	for (int i = 0; i < board.memory.size() + 1; ++i) {
		for (int j = 0; j < board.memory.size() + 1; ++j) {
			if (i == 0 && j == 0) {
				std::cout << "   p";
			} else if (i == 0) {
				std::cout << " <" << j - 1 << ">";
			} else if (j == 0) {
				std::cout << "<" << i - 1 << ">";
			}
			else {
				if (!board.memory[i-1][j-1]) {
					std::cout << "  - ";
				}
				else {
					std::cout << "  " << board.memory[i-1][j-1] << " ";
				}
			}
		}
		std::cout << "\n\n";
	}
}