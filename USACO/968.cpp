#include <cstdio>
#include <iostream>
#include <vector>

int N, M;
std::vector<char> farms;
std::vector<std::vector<int>> adj;
std::vector<int> comp;

void dfs(int node, char type, int id) {
	if (comp[node] || farms[node] != type)
		return;
	comp[node] = id;

	for (int u : adj[node])
		dfs(u, type, id);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	std::cin >> N >> M;
	farms.resize(N);
	adj.resize(N);
	comp.assign(N, 0);

	for (int i = 0; i < N; ++i)
		std::cin >> farms[i];

	for (int i = 0; i < N - 1; ++i) {
		int X, Y;
		std::cin >> X >> Y;
		--X;
		--Y;

		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	int id = 1;
	for (int i = 0; i < N; ++i) {
		if (comp[i])
			continue;

		dfs(i, farms[i], id);
		++id;
	}

	for (int i = 0; i < M; ++i) {
		int A, B;
		char C;
		std::cin >> A >> B >> C;
		--A;
		--B;

		if (comp[A] == comp[B])
			std::cout << (C == farms[A]);
		else
			std::cout << 1;
	}

	std::cout << std::endl;

	return 0;
}
