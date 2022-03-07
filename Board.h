#ifndef BOARD_H
#define BOARD_H

// Author: Juan Carlos Juárez
// GNU/Linux Tic Tac Toe
// 'Board.h'

#include <vector>
#include <utility>

namespace TicTacToe {
	class Board {

		public:
			std::vector<std::pair<bool, std::pair<int, int>>> rows;
			std::vector<std::pair<bool, std::pair<int, int>>> cols;
			std::pair<bool, std::pair<int, int>> diag1;
			std::pair<bool, std::pair<int, int>> diag2;
			std::vector<std::vector<int>> memory;
			int size;
			int winner;
			Board(int);

	};
	void displayBoard(TicTacToe::Board&);
}

#endif
