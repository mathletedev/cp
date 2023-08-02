#include <cstdlib>
#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<int> component;

void ff(int node, int colour) {
	if (component[node] == colour)
		return;

	component[node] = colour;
	for (int u : adj[node])
		ff(u, colour);
}

void solve() {
	std::cin >> N >> M;
	adj.assign(N, std::vector<int>());
	component.assign(N, -1);

	for (int i = 0; i < M; ++i) {
		int a, b;
		std::cin >> a >> b;
		--a, --b;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int colour = 0;
	for (int i = 0; i < N; ++i) {
		if (component[i] != -1)
			continue;

		ff(i, colour++);
	}

	std::vector<std::vector<int>> trees(colour);
	for (int i = 0; i < N; ++i)
		trees[component[i]].push_back(i);

	std::vector<long long> dists_start(colour, INT64_MAX);
	std::vector<long long> dists_end(colour, INT64_MAX);

	int index_start = 0, index_end = 0;

	for (int i = 0; i < N; ++i) {
		while (index_start < trees[component[0]].size()) {
			dists_start[component[i]] = std::min<long long>(
			    dists_start[component[i]],
			    (long long)std::abs(
				trees[component[0]][index_start] - i));

			if (trees[component[0]][index_start] >= i)
				break;
			++index_start;
		}
		if (index_start)
			--index_start;

		while (index_end < trees[component[N - 1]].size()) {
			dists_end[component[i]] = std::min<long long>(
			    dists_end[component[i]],
			    (long long)std::abs(
				trees[component[N - 1]][index_end] - i));

			if (trees[component[N - 1]][index_end] >= i)
				break;
			++index_end;
		}
		if (index_end)
			--index_end;
	}

	long long ans = INT64_MAX;
	for (int i = 0; i < colour; ++i)
		ans = std::min<long long>(dists_start[i] * dists_start[i] +
					      dists_end[i] * dists_end[i],
					  ans);

	std::cout << ans << std::endl;
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
