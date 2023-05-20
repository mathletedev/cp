#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> pos;
std::vector<int> powers;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

int square(int x) { return x * x; }

void dfs(int node) {
	visited[node] = true;
	for (int u : adj[node])
		if (!visited[u])
			dfs(u);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int n;
	std::cin >> n;

	adj.resize(n);
	pos.resize(n);
	powers.resize(n);
	visited.resize(n);

	for (int i = 0; i < n; ++i) {
		int x, y, p;
		std::cin >> x >> y >> p;

		pos[i] = {x, y};
		powers[i] = p;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (j == i)
				continue;

			if (square(pos[i].first - pos[j].first) +
				square(pos[i].second - pos[j].second) <=
			    square(powers[i]))
				adj[i].push_back(j);
		}
	}

	int best = 0;
	for (int i = 0; i < n; ++i) {
		std::fill(visited.begin(), visited.end(), false);

		dfs(i);
		int count = std::count(visited.begin(), visited.end(), true);
		best = std::max(best, count);
	}

	std::cout << best << std::endl;

	return 0;
}
