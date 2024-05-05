#include <iostream>
#include <vector>

int N, K;
std::vector<int> T;
std::vector<std::vector<int>> adj;
long long visited = 0;

// visit all linked farmers
void dfs(int node) {
	if (visited & (1 << node)) return;
	visited |= 1 << node;

	for (int u : adj[node])
		dfs(u);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	std::cin >> N >> K;
	T.assign(N, 0);
	adj.assign(N, std::vector<int>());

	for (int &x : T)
		std::cin >> x;

	std::vector<int> farmers = std::vector<int>(K);
	long long time = 0;
	for (int i = 0; i < N; ++i) {
		// initial interviews
		if (i < K) {
			farmers[i] = T[i];
			continue;
		}

		// find min
		int min = INT32_MAX;
		for (int x : farmers)
			min = std::min(x, min);

		time += min;

		std::vector<int> available;
		for (int j = 0; j < K; ++j) {
			// step time
			farmers[j] -= min;
			if (farmers[j] == 0) {
				// next cow
				if (available.empty()) farmers[j] = T[i];

				available.push_back(j);
			}
		}

		// link same-time interviews
		for (int j = 0; j < available.size(); ++j) {
			for (int k = j + 1; k < available.size(); ++k) {
				adj[j].push_back(k);
				adj[k].push_back(j);
			}
		}
	}

	int min = INT32_MAX;
	for (int x : farmers)
		min = std::min(x, min);

	time += min;

	// link backwards
	for (int i = 0; i < K; ++i)
		if (farmers[i] == min) dfs(i);

	std::cout << time << std::endl;
	for (int i = 0; i < K; ++i)
		std::cout << !!(visited & (1 << i));
	std::cout << std::endl;

	return 0;
}
