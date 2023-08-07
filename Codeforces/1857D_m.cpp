#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A, B;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> transpose;
std::vector<bool> visited;

void dfs(int node) {
	if (visited[node])
		return;

	visited[node] = 1;
	for (int u : adj[node])
		dfs(u);
}

void solve() {
	std::cin >> N;
	A.assign(N, 0), B.assign(N, 0);
	adj.assign(N, std::vector<int>()),
	    transpose.assign(N, std::vector<int>());

	for (int &x : A)
		std::cin >> x;
	for (int &x : B)
		std::cin >> x;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (A[j] - A[i] >= B[j] - B[i]) {
				adj[j].push_back(i);
				transpose[i].push_back(j);
			}
		}
	}

	visited.assign(N, 0);
	int strong_vertex = 0;
	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			dfs(i);
			strong_vertex = i;
		}
	}

	visited.assign(N, 0);
	adj = transpose;
	dfs(strong_vertex);

	std::cout << std::count(visited.begin(), visited.end(), 1) << std::endl;
	for (int i = 0; i < N; ++i) {
		if (visited[i])
			std::cout << i + 1 << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
