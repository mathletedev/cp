#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> adj;
std::vector<int> dp;

int dfs(int node) {
	if (dp[node] != -1)
		return dp[node];

	int max = 0;
	for (int u : adj[node])
		max = std::max(max, dfs(u) + 1);

	return dp[node] = max;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	adj.assign(N + 1, {});
	dp.assign(N + 1, -1);

	for (int i = 0; i < M; ++i) {
		int X, Y;
		std::cin >> X >> Y;

		adj[X].push_back(Y);
	}

	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = std::max(ans, dfs(i));

	std::cout << ans << std::endl;

	return 0;
}
