#include <iostream>
#include <vector>

int R, C;
std::vector<std::vector<char>> board;
std::vector<std::vector<int>> colour;
std::vector<std::vector<bool>> visited;
std::vector<int> num_free;

bool is_free(int r, int c) {
	if (r < 0 || r >= R || c < 0 || c >= C || visited[r][c])
		return 0;
	visited[r][c] = 1;

	return board[r][c] == '.';
}

void dfs(int r, int c, int i) {
	if ((r < 0 || r >= R) || (c < 0 || c >= C) || board[r][c] != 'W' ||
	    colour[r][c])
		return;

	colour[r][c] = i;

	dfs(r + 1, c, i);
	dfs(r - 1, c, i);
	dfs(r, c + 1, i);
	dfs(r, c - 1, i);

	if (is_free(r + 1, c))
		++num_free[i];
	if (is_free(r - 1, c))
		++num_free[i];
	if (is_free(r, c + 1))
		++num_free[i];
	if (is_free(r, c - 1))
		++num_free[i];
}

void solve() {
	std::cin >> R >> C;

	board.assign(R, std::vector<char>(C));
	colour.assign(R, std::vector<int>(C, 0));
	num_free.assign(1000, 0);

	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c)
			std::cin >> board[r][c];
	}

	int curr = 0;
	for (int r = 0; r < R; ++r) {
		for (int c = 0; c < C; ++c) {
			if (board[r][c] == 'W' && !colour[r][c]) {
				visited.assign(R, std::vector<bool>(C, 0));
				dfs(r, c, ++curr);
			}
		}
	}

	std::string ans = "NO";
	for (int i = 1; i <= curr; ++i) {
		if (num_free[i] < 2)
			ans = "YES";
	}
	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
