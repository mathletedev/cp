#include <cstdint>
#include <functional>
#include <iostream>

#define ROWS 6
#define COLS 7

int count(bool grid[ROWS][COLS], std::function<bool(int, int)> f, bool first) {
	int res[2] = {0, 0};

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			if (f(i, j)) {
				++res[grid[i][j]];
			}
		}
	}

	return std::max(res[0], res[1]) * 2 - first;
}

char solve() {
	bool grid[ROWS][COLS];
	for (int i = ROWS - 1; i >= 0; --i) {
		for (int j = 0; j < COLS; ++j) {
			char c;
			std::cin >> c;

			grid[i][j] = c == 'C';
		}
	}

	int min[2] = {INT32_MAX, INT32_MAX};
	int max[2] = {INT32_MAX, INT32_MAX};

	for (int i = 0; i < ROWS; ++i) {
		for (int j = 0; j < COLS; ++j) {
			bool b = grid[i][j];

			for (int n = 3; true; ++n) {
				if (i + n >= ROWS) {
					break;
				}

				bool valid = true;
				for (int k = 1; k <= n; ++k) {
					if (grid[i + k][j] != b) {
						valid = false;
						break;
					}
				}

				if (!valid) {
					break;
				}

				auto f1 = [&i, &j, &n](int _i, int _j) -> bool {
					return _j == j && _i <= i + n;
				};

				auto f2 = [&i, &j](int _i, int _j) -> bool {
					return _j != j || _i <= i + 3;
				};

				min[b] = std::min(min[b], count(grid, f1, b));
				max[b] = std::min(max[b], count(grid, f2, b));
			}

			for (int n = 3; true; ++n) {
				if (j + n >= COLS) {
					break;
				}

				bool valid = true;
				for (int k = 1; k <= n; ++k) {
					if (grid[i][j + k] != b) {
						valid = false;
						break;
					}
				}

				if (!valid) {
					break;
				}

				auto f1 = [&i, &j, &n](int _i, int _j) -> bool {
					return _j >= j && _j <= j + n &&
					       _i <= i;
				};

				auto f2 = [&i, &j](int _i, int _j) -> bool {
					return _j < j || _j > j + 3 || _i <= i;
				};

				min[b] = std::min(min[b], count(grid, f1, b));
				max[b] = std::min(max[b], count(grid, f2, b));
			}

			for (int n = 3; true; ++n) {
				if (i + n >= ROWS || j + n >= COLS) {
					break;
				}

				bool valid = true;
				for (int k = 1; k <= n; ++k) {
					if (grid[i + k][j + k] != b) {
						valid = false;
						break;
					}
				}

				if (!valid) {
					break;
				}

				auto f1 = [&i, &j, &n](int _i, int _j) -> bool {
					return _j >= j && _j <= j + n &&
					       _i <= i + _j - j;
				};
				auto f2 = [&i, &j](int _i, int _j) -> bool {
					return _j < j || _j > j + 3 ||
					       _i <= i + _j - j;
				};

				min[b] = std::min(min[b], count(grid, f1, b));
				max[b] = std::min(max[b], count(grid, f2, b));
			}

			for (int n = 3; true; ++n) {
				if (i + n >= ROWS || j - n < 0) {
					break;
				}

				bool valid = true;
				for (int k = 1; k <= n; ++k) {
					if (grid[i + k][j - k] != b) {
						valid = false;
						break;
					}
				}

				if (!valid) {
					break;
				}

				auto f1 = [&i, &j, &n](int _i, int _j) -> bool {
					return _j <= j && _j >= j - n &&
					       _i <= i + j - _j;
				};
				auto f2 = [&i, &j](int _i, int _j) -> bool {
					return _j < j || _j > j - 3 ||
					       _i <= i + j - _j;
				};
				min[b] = std::min(min[b], count(grid, f1, b));
				max[b] = std::min(max[b], count(grid, f2, b));
			}
		}
	}

	std::cout << min[0] << " " << max[0] << " " << min[1] << " " << max[1]
		  << std::endl;

	if (min[0] == INT32_MAX && min[1] == INT32_MAX && max[0] == INT32_MAX &&
	    max[1] == INT32_MAX) {
		return '0';
	}

	if (max[1] < max[0]) {
		return 'C';
	}

	if (max[0] < max[1]) {
		return 'F';
	}

	return '?';
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": " << solve() << std::endl;
	}

	return 0;
}
