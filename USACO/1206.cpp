#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> cows;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> path_exists;

void dfs(int node, int target) {
	if (path_exists[node][target])
		return;

	path_exists[node][target] = 1;
	for (int u : adj[node])
		dfs(u, target);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;
	cows.assign(N, std::vector<int>(N));
	adj.assign(N, {});
	path_exists.assign(N, std::vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			std::cin >> cows[i][j], --cows[i][j];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (cows[i][j] == i)
				break;
			adj[i].push_back(cows[i][j]);
		}
	}

	for (int i = 0; i < N; ++i)
		dfs(i, i);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (path_exists[i][cows[i][j]]) {
				std::cout << cows[i][j] + 1 << std::endl;
				break;
			}
		}
	}

	return 0;
}
