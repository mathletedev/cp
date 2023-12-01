#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<char>> maze;
std::vector<std::vector<bool>> visited;

int block(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;

	if (maze[x][y] == 'G' || (x == N - 1 && y == M - 1))
		return 1;

	maze[x][y] = '#';
	return 0;
}

int dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M || visited[x][y] ||
	    maze[x][y] == '#')
		return 0;
	visited[x][y] = 1;

	int res = 0;
	res += dfs(x + 1, y);
	res += dfs(x - 1, y);
	res += dfs(x, y + 1);
	res += dfs(x, y - 1);

	if (maze[x][y] == 'G')
		++res;

	return res;
}

void solve() {
	std::cin >> N >> M;
	maze.assign(N, std::vector<char>(M));
	visited.assign(N, std::vector<bool>(M, 0));

	std::vector<std::pair<int, int>> bad;

	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cin >> maze[i][j];

			if (maze[i][j] == 'G')
				++count;
			else if (maze[i][j] == 'B')
				bad.push_back({i, j});
		}
	}

	if (count == 0) {
		std::cout << "YES" << std::endl;
		return;
	}

	for (auto b : bad) {
		int i = b.first, j = b.second;

		if (block(i + 1, j) || block(i - 1, j) || block(i, j + 1) ||
		    block(i, j - 1)) {
			std::cout << "NO" << std::endl;
			return;
		}
	}

	std::cout << (dfs(N - 1, M - 1) == count ? "YES" : "NO") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
