// Author: Juan Carlos Juárez
// GNU/Linux Tic Tac Toe
// 'Move.cpp'

#include <vector>
#include <utility>
#include "Move.h"

namespace TicTacToe {

	int move(int player, int row, int col, TicTacToe::Board& board) {

		// Check for winner
		if (board.winner) return board.winner;

		// Check Boundaries
		if (row < 0 || row >= board.size || col < 0 || col >= board.size) return -1;

		// Check for filled cell
		if (board.memory[row][col]) return -2;

		// Assigns cell to player
		board.memory[row][col] = player;

		// Analyze Rows
		if (board.rows[row].first) {
			if (board.rows[row].second.first != 0 && board.rows[row].second.first != player) {
				board.rows[row].first = false;
			}
			else {
				board.rows[row].second.first = player;
				board.rows[row].second.second++;
				if (board.rows[row].second.second == board.size) {
					board.winner = player;
					return board.winner;
				}
			}
		}

		// Analyze Columns
		if (board.cols[col].first) {
			if (board.cols[col].second.first != 0 && board.cols[col].second.first != player) {
				board.cols[col].first = false;
			}
			else {
				board.cols[col].second.first = player;
				board.cols[col].second.second++;
				if (board.cols[col].second.second == board.size) {
					board.winner = player;
					return board.winner;
				}
			}
		}

		// Analyze First Diagonal
		if (row == col && board.diag1.first) {
			if (board.diag1.second.first != 0 && board.diag1.second.first != player) {
				board.diag1.first = false;
			}
			else {
				board.diag1.second.first = player;
				board.diag1.second.second++;
				if (board.diag1.second.second == board.size) {
					board.winner = player;
					return board.winner;
				}
			}
		}

		// Analyze Second Diagonal
		if ((row + col == board.size - 1) && board.diag2.first) {
			if (board.diag2.second.first != 0 && board.diag2.second.first != player) {
				board.diag2.first = false;
			}
			else {
				board.diag2.second.first = player;
				board.diag2.second.second++;
				if (board.diag2.second.second == board.size) {
					board.winner = player;
					return board.winner;
				}
			}
		}

		return 0;

	}

}