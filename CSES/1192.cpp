#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<char>> graph;
std::vector<std::vector<bool>> visited;

void dfs(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M || graph[r][c] == '#' ||
	    visited[r][c])
		return;
	visited[r][c] = 1;

	dfs(r + 1, c);
	dfs(r - 1, c);
	dfs(r, c + 1);
	dfs(r, c - 1);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	graph.assign(N, std::vector<char>(M));
	visited.assign(N, std::vector<bool>(M, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j)
			std::cin >> graph[i][j];
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (graph[i][j] == '#' || visited[i][j])
				continue;

			dfs(i, j);
			++ans;
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
