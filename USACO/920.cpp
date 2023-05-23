#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <ostream>
#include <vector>

std::vector<std::vector<std::pair<int, bool>>> adj;
std::vector<int> visited;
bool impossible = false;

void colour(int node, int c) {
	if (c != visited[node] && visited[node] != 0)
		impossible = true;
	if (impossible || visited[node] != 0)
		return;

	visited[node] = c;

	for (std::pair<int, bool> u : adj[node])
		colour(u.first, c * (u.second ? 1 : -1));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	adj.resize(n);
	visited.resize(n);
	std::fill(visited.begin(), visited.end(), 0);

	for (int i = 0; i < m; ++i) {
		char c;
		int a, b;
		std::cin >> c >> a >> b;
		a--;
		b--;
		int same = (c == 'S');

		adj[a].push_back({b, same});
		adj[b].push_back({a, same});
	}

	int trees = 0;
	for (int i = 0; i < n; ++i) {
		if (adj[i].size() > 0 && visited[i] == 0) {
			++trees;
			colour(i, 1);

			if (impossible) {
				std::cout << 0 << std::endl;
				return 0;
			}
		}
	}

	int empty = std::count(visited.begin(), visited.end(), false);
	std::cout << "1" << std::string(empty + trees, '0') << std::endl;

	return 0;
}
