#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
long long even = 0, odd = 0;

void dfs(int node, int parity) {
	if (visited[node])
		return;
	visited[node] = 1;

	++(parity == 0 ? even : odd);

	for (int u : adj[node])
		dfs(u, parity ^ 1);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	adj.assign(N, std::vector<int>());
	visited.assign(N, 0);

	for (int i = 0; i < N - 1; ++i) {
		int U, V;
		std::cin >> U >> V, --U, --V;

		adj[U].push_back(V);
		adj[V].push_back(U);
	}

	dfs(0, 0);

	std::cout << even * odd - (N - 1) << std::endl;

	return 0;
}
