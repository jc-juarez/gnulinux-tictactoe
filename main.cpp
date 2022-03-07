// Author: Juan Carlos Juárez
// GNU/Linux Tic Tac Toe
// 'main.cpp'

#include <iostream>
#include "Board.h"
#include "Move.h"

int main()
{
	int board_size{};
	std::cout << "\n<<< Welcome to GNU/Linux Tic Tac Toe >>> \n";
	std::cout << "--- Implementation by Juan Carlos Juarez --- \n\n";
	do {
		std::cout << "Please insert Board size: ";
		std::cin >> board_size;
		if(board_size < 2 || board_size > 8) std::cerr << "\nPlease insert a Board Size of at least 2x2 and not larger than 8x8.\n\n";
	} while (board_size < 2 || board_size > 8);
	TicTacToe::Board board(board_size);
	std::cout << "\nGame on!";
	TicTacToe::displayBoard(board);
	bool changer = true;
	while (!board.winner) {
		int player = changer ? 1 : 2;
		changer = !changer;
		int row{};
		int col{};
		int move_status{};
		do {
			std::cout << "\n* Player " << player << " Turn *\n";
			std::cout << "Select Row: ";
			std::cin >> row;
			std::cout << "Select Column: ";
			std::cin >> col;
			move_status = TicTacToe::move(player, row, col, board);
			if (move_status == -1) {
				std::cerr << "\nPlease select valid Boundaries inside the Board.\n";
			}
			else if (move_status == -2) {
				std::cerr << "\nThis position is already filled. Please select a valid position inside the Board.\n";
			}
			else if (move_status) {
				std::cout << "\n<<< Player " << player << " has won! >>>";
			}
		} while (move_status == -1 || move_status == -2);
		TicTacToe::displayBoard(board);
	}
	return 0;
}