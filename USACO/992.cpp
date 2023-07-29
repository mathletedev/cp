#include <cstdio>
#include <iostream>
#include <vector>

int N, M;
std::vector<int> locations;
std::vector<std::vector<int>> adj;
std::vector<int> component;

struct Wormhole {
	int a, b, w;
};
std::vector<Wormhole> wormholes;

void ff(int node, int colour) {
	if (component[node] != 0)
		return;

	component[node] = colour;
	for (int u : adj[node])
		ff(u, colour);
}

bool is_possible(int x) {
	adj.assign(N, std::vector<int>());
	component.assign(N, 0);
	for (Wormhole w : wormholes) {
		if (w.w >= x) {
			adj[w.a].push_back(w.b);
			adj[w.b].push_back(w.a);
		}
	}

	int colour = 1;
	for (int i = 0; i < N; ++i) {
		if (component[i] != 0)
			continue;

		ff(i, colour);
		++colour;
	}

	for (int i = 0; i < N; ++i) {
		if (component[locations[i]] != component[i])
			return 0;
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	std::cin >> N >> M;
	locations.assign(N, 0);

	for (int &x : locations)
		std::cin >> x, --x;

	for (int i = 0; i < N; ++i) {
		if (locations[i] != i)
			goto unsorted;
	}
	std::cout << -1 << std::endl;

	return 0;

unsorted:;
	for (int i = 0; i < M; ++i) {
		int a, b, w;
		std::cin >> a >> b >> w;
		--a, --b;

		wormholes.push_back({a, b, w});
	}

	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high) / 2 + (low + high) % 2;

		if (is_possible(mid))
			low = mid;
		else
			high = mid - 1;
	}

	std::cout << low << std::endl;

	return 0;
}
