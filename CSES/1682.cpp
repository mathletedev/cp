#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj, transpose;
std::vector<bool> visited;

void dfs(int node, std::vector<std::vector<int>> &adj) {
	if (visited[node])
		return;

	visited[node] = 1;
	for (int u : adj[node])
		dfs(u, adj);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	adj.assign(N, std::vector<int>());
	transpose.assign(N, std::vector<int>());

	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B, --A, --B;

		adj[A].push_back(B);
		transpose[B].push_back(A);
	}

	visited.assign(N, 0);
	dfs(0, adj);

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			std::cout << "NO" << std::endl;
			std::cout << 1 << " " << i + 1 << std::endl;
			return 0;
		}
	}

	visited.assign(N, 0);
	dfs(0, transpose);

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			std::cout << "NO" << std::endl;
			std::cout << i + 1 << " " << 1 << std::endl;
			return 0;
		}
	}

	std::cout << "YES" << std::endl;

	return 0;
}
