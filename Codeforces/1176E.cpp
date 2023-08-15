#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<int> distance;

void dfs(int node, int depth) {
	if (distance[node])
		return;

	distance[node] = depth;
	for (int u : adj[node])
		dfs(u, depth + 1);
}

void solve() {
	std::cin >> N >> M;
	adj.assign(N, std::vector<int>());
	distance.assign(N, 0);

	for (int i = 0; i < M; ++i) {
		int V, U;
		std::cin >> V >> U, --V, --U;

		adj[V].push_back(U);
		adj[U].push_back(V);
	}

	dfs(0, 1);

	int num_even = 0;
	for (int i = 0; i < N; ++i) {
		if (distance[i] % 2)
			++num_even;
	}

	std::vector<int> ans;
	for (int i = 0; i < N; ++i) {
		if (distance[i] % 2 == (num_even <= N - num_even))
			ans.push_back(i);
	}

	std::cout << ans.size() << std::endl;
	for (int x : ans)
		std::cout << x + 1 << " ";
	std::cout << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
