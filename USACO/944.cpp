#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> pos;
std::vector<std::vector<int>> adj;
std::vector<int> visited;
int minX, maxX, minY, maxY;

void dfs(int node) {
	visited[node] = true;

	minX = std::min(minX, pos[node].first);
	maxX = std::max(maxX, pos[node].first);
	minY = std::min(minY, pos[node].second);
	maxY = std::max(maxY, pos[node].second);

	for (int u : adj[node])
		if (!visited[u])
			dfs(u);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	pos.resize(n);
	adj.resize(n);
	visited.resize(n);
	std::fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < n; ++i) {
		int x, y;
		std::cin >> x >> y;

		pos[i] = {x, y};
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;

		--a;
		--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int best = INT32_MAX;
	for (int i = 0; i < n; ++i) {
		if (visited[i])
			continue;

		minX = minY = INT32_MAX;
		maxX = maxY = 0;

		dfs(i);
		best = std::min(best, (maxX - minX) * 2 + (maxY - minY) * 2);
	}

	std::cout << best << std::endl;

	return 0;
}
