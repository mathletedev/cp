#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> adj;
std::vector<bool> visited;
int end_node, max_depth;

void dfs(int node, int depth) {
	if (visited[node])
		return;

	if (depth > max_depth)
		max_depth = depth, end_node = node;

	visited[node] = 1;
	for (int u : adj[node])
		dfs(u, depth + 1);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	adj.assign(N, std::vector<int>());

	for (int i = 0; i < N - 1; ++i) {
		int A, B;
		std::cin >> A >> B, --A, --B;

		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	visited.assign(N, 0);
	max_depth = -1;
	dfs(0, 0);

	visited.assign(N, 0);
	max_depth = -1;
	dfs(end_node, 0);

	std::cout << max_depth << std::endl;

	return 0;
}
