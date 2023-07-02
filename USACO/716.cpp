#include <algorithm>
#include <iostream>
#include <vector>

int N, K, R;
std::vector<std::pair<int, int>> cows;
std::vector<std::vector<int>> grid;
std::vector<std::vector<std::vector<std::pair<int, int>>>> adj;
std::vector<std::vector<bool>> visited;
int pairs = 0;

void dfs(int i, int j, int c) {
	if ((i < 0 || i >= N || j < 0 || j >= N) || visited[i][j])
		return;

	visited[i][j] = true;
	if (grid[i][j] != -1 && grid[i][j] != c)
		++pairs;

	std::vector<std::pair<int, int>> roads = adj[i][j];

	if (!std::count(roads.begin(), roads.end(), std::make_pair(i + 1, j)))
		dfs(i + 1, j, c);
	if (!std::count(roads.begin(), roads.end(), std::make_pair(i - 1, j)))
		dfs(i - 1, j, c);
	if (!std::count(roads.begin(), roads.end(), std::make_pair(i, j + 1)))
		dfs(i, j + 1, c);
	if (!std::count(roads.begin(), roads.end(), std::make_pair(i, j - 1)))
		dfs(i, j - 1, c);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	std::cin >> N >> K >> R;
	grid.resize(N, std::vector<int>(N, -1));
	adj.resize(N, std::vector<std::vector<std::pair<int, int>>>(N));
	visited.resize(N, std::vector<bool>(N));
	cows.resize(K);

	for (int i = 0; i < R; ++i) {
		int i1, j1, i2, j2;
		std::cin >> i1 >> j1 >> i2 >> j2;
		--i1;
		--j1;
		--i2;
		--j2;

		adj[i1][j1].push_back({i2, j2});
		adj[i2][j2].push_back({i1, j1});
	}

	for (int i = 0; i < K; ++i) {
		int ci, cj;
		std::cin >> ci >> cj;
		--ci;
		--cj;

		cows[i] = {ci, cj};
		grid[ci][cj] = i;
	}

	for (int i = 0; i < K; ++i) {
		std::fill(visited.begin(), visited.end(),
			  std::vector<bool>(N, false));
		dfs(cows[i].first, cows[i].second, i);
	}

	std::cout << (K * (K - 1) - pairs) / 2 << std::endl;

	return 0;
}
