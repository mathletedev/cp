#include <cstdio>
#include <iostream>
#include <vector>

struct Cow {
	int x, y;
};

int N;
std::vector<Cow> cows;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

void dfs(int node) {
	if (visited[node])
		return;

	visited[node] = 1;
	for (int u : adj[node])
		dfs(u);
}

int square(int x) { return x * x; }

bool is_possible(int X) {
	adj.assign(N, std::vector<int>());

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (square(cows[i].x - cows[j].x) +
				square(cows[i].y - cows[j].y) <=
			    X) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	visited.assign(N, 0);
	dfs(0);

	for (bool v : visited) {
		if (!v)
			return 0;
	}
	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;

		cows.push_back({x, y});
	}

	int low = 0, high = INT32_MAX;
	while (low < high) {
		int mid = (low + high) / 2;

		if (is_possible(mid))
			high = mid;
		else
			low = mid + 1;
	}

	std::cout << low << std::endl;

	return 0;
}
