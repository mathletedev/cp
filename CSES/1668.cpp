#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<int> component;
bool impossible = 0;

void dfs(int node, int colour) {
	if (component[node])
		return;

	component[node] = colour;
	for (int u : adj[node]) {
		if (component[u] == colour) {
			impossible = 1;
			return;
		}
		dfs(u, colour == 1 ? 2 : 1);
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	adj.assign(N, std::vector<int>());
	component.assign(N, 0);

	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B, --A, --B;

		adj[A].push_back(B);
		adj[B].push_back(A);
	}

	for (int i = 0; i < N; ++i) {
		if (!component[i])
			dfs(i, 1);
	}

	if (impossible)
		std::cout << "IMPOSSIBLE" << std::endl;
	else {
		for (int c : component)
			std::cout << c << " ";
		std::cout << std::endl;
	}

	return 0;
}
