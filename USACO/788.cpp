#include <cstdio>
#include <iostream>
#include <vector>

int N, Q;
std::vector<std::vector<std::pair<int, int>>> adj;
std::vector<bool> visited;
int count, k;

void dfs(int node, int rel) {
	visited[node] = true;

	for (std::pair<int, int> u : adj[node]) {
		if (visited[u.first])
			continue;

		int minRel = std::min(rel, u.second);

		if (minRel >= k)
			++count;
		dfs(u.first, minRel);
	}
}

void solve() {
	int v;
	std::cin >> k >> v;
	--v;

	count = 0;
	std::fill(visited.begin(), visited.end(), false);
	dfs(v, INT32_MAX);

	std::cout << count << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	std::cin >> N >> Q;
	adj.resize(N);
	visited.resize(N);

	for (int i = 0; i < N - 1; ++i) {
		int p, q, r;
		std::cin >> p >> q >> r;
		--p;
		--q;

		adj[p].push_back({q, r});
		adj[q].push_back({p, r});
	}

	for (int i = 0; i < Q; ++i)
		solve();

	return 0;
}
