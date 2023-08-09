#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;

void dfs(int node) {
	if (visited[node])
		return;

	visited[node] = 1;
	for (int u : adj[node])
		dfs(u);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	adj.assign(N, std::vector<int>());
	visited.assign(N, 0);

	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B, --A, --B;

		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	dfs(0);

	std::vector<std::pair<int, int>> ans;
	for (int i = 0; i < N; ++i) {
		if (visited[i])
			continue;

		ans.push_back({1, i + 1});
		dfs(i);
	}

	std::cout << ans.size() << std::endl;
	for (std::pair<int, int> a : ans)
		std::cout << a.first << " " << a.second << std::endl;

	return 0;
}
