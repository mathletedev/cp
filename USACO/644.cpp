#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> adj;
std::vector<bool> visited;
std::vector<bool> closed;

void dfs(int node) {
	if (closed[node])
		return;

	visited[node] = true;
	for (int u : adj[node])
		if (!visited[u])
			dfs(u);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	adj.resize(n);
	visited.resize(n);
	closed.resize(n);
	std::fill(closed.begin(), closed.end(), false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a;
		--b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i < n; ++i) {
		int barn;
		std::cin >> barn;
		barn--;

		std::fill(visited.begin(), visited.end(), false);

		int init = 0;
		while (closed[init])
			++init;

		dfs(init);

		std::cout
		    << (std::count(visited.begin(), visited.end(), true) ==
				std::count(closed.begin(), closed.end(), false)
			    ? "YES"
			    : "NO")
		    << std::endl;

		closed[barn] = true;
	}

	return 0;
}
