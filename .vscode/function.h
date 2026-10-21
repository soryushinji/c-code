#ifndef FUNCTION_H
#define FUNCTION_H

#include <algorithm>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class Minesweeper {
public:
	Minesweeper(int rows = 9, int cols = 9, int mineCount = 10)
		: rows_(rows), cols_(cols), mineCount_(mineCount),
		  board_(rows, std::vector<Cell>(cols)), rng_(std::random_device{}()),
		  minesPlaced_(false), gameOver_(false) {
		if (rows <= 0 || cols <= 0 || mineCount < 0 || mineCount >= rows * cols) {
			throw std::invalid_argument("Invalid board dimensions or mine count.");
		}
	}

	// Start a console game. Commands: r row col (reveal), f row col (flag), q (quit).
	void run() {
		std::cout << "Minesweeper: " << rows_ << "x" << cols_ << ", " << mineCount_
				  << " mines. Coordinates start at 1.\n"
				  << "Commands: r row col = reveal, f row col = flag, q = quit\n";
		printBoard(false);

		std::string command;
		while (!gameOver_) {
			std::cout << "> ";
			if (!(std::cin >> command)) return;
			if (command == "q" || command == "Q") return;

			int row, col;
			if (!(std::cin >> row >> col)) {
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cout << "Enter a command followed by row and column.\n";
				continue;
			}
			--row;
			--col;
			if (!inBounds(row, col)) {
				std::cout << "Coordinates are outside the board.\n";
				continue;
			}

			if (command == "r" || command == "R") {
				reveal(row, col);
			} else if (command == "f" || command == "F") {
				toggleFlag(row, col);
			} else {
				std::cout << "Unknown command. Use r, f, or q.\n";
				continue;
			}

			printBoard(gameOver_);
			if (gameOver_) {
				if (won()) std::cout << "You win!\n";
				else std::cout << "Boom! Game over.\n";
			}
		}
	}

private:
	struct Cell {
		bool mine = false;
		bool revealed = false;
		bool flagged = false;
		int adjacent = 0;
	};

	int rows_;
	int cols_;
	int mineCount_;
	std::vector<std::vector<Cell>> board_;
	std::mt19937 rng_;
	bool minesPlaced_;
	bool gameOver_;

	bool inBounds(int row, int col) const {
		return row >= 0 && row < rows_ && col >= 0 && col < cols_;
	}

	void placeMines(int safeRow, int safeCol) {
		std::vector<int> positions;
		positions.reserve(rows_ * cols_ - 1);
		for (int r = 0; r < rows_; ++r) {
			for (int c = 0; c < cols_; ++c) {
				if (r != safeRow || c != safeCol) positions.push_back(r * cols_ + c);
			}
		}
		std::shuffle(positions.begin(), positions.end(), rng_);
		for (int i = 0; i < mineCount_; ++i) {
			int r = positions[i] / cols_;
			int c = positions[i] % cols_;
			board_[r][c].mine = true;
		}

		for (int r = 0; r < rows_; ++r) {
			for (int c = 0; c < cols_; ++c) {
				if (board_[r][c].mine) continue;
				for (int dr = -1; dr <= 1; ++dr) {
					for (int dc = -1; dc <= 1; ++dc) {
						int nr = r + dr, nc = c + dc;
						if (inBounds(nr, nc) && board_[nr][nc].mine)
							++board_[r][c].adjacent;
					}
				}
			}
		}
		minesPlaced_ = true;
	}

	void reveal(int row, int col) {
		Cell& cell = board_[row][col];
		if (cell.flagged || cell.revealed) return;
		if (!minesPlaced_) placeMines(row, col);
		if (cell.mine) {
			gameOver_ = true;
			return;
		}

		cell.revealed = true;
		if (cell.adjacent == 0) {
			for (int dr = -1; dr <= 1; ++dr) {
				for (int dc = -1; dc <= 1; ++dc) {
					int nr = row + dr, nc = col + dc;
					if (inBounds(nr, nc) && !board_[nr][nc].revealed)
						reveal(nr, nc);
				}
			}
		}
		if (won()) gameOver_ = true;
	}

	void toggleFlag(int row, int col) {
		Cell& cell = board_[row][col];
		if (!cell.revealed) cell.flagged = !cell.flagged;
	}

	bool won() const {
		for (int r = 0; r < rows_; ++r)
			for (int c = 0; c < cols_; ++c)
				if (!board_[r][c].mine && !board_[r][c].revealed) return false;
		return true;
	}

	void printBoard(bool revealMines) const {
		std::cout << "    ";
		for (int c = 0; c < cols_; ++c) std::cout << (c + 1) % 10 << ' ';
		std::cout << "\n";
		for (int r = 0; r < rows_; ++r) {
			std::cout.width(3);
			std::cout << r + 1 << ' ';
			for (int c = 0; c < cols_; ++c) {
				const Cell& cell = board_[r][c];
				char symbol = '#';
				if (cell.flagged && !cell.revealed) symbol = 'F';
				else if (cell.revealed || (revealMines && cell.mine))
					symbol = cell.mine ? '*' : (cell.adjacent ? char('0' + cell.adjacent) : ' ');
				std::cout << symbol << ' ';
			}
			std::cout << '\n';
		}
	}
};

#endif // FUNCTION_H
