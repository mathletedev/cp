#include <cstdio>
#include <iostream>
#include <vector>

const int MAX_DAYS = 1000;

int N, M, C;
std::vector<int> cities;
std::vector<std::vector<int>> adj;
std::vector<std::vector<int>> dp;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("time.in", "r", stdin);
	freopen("time.out", "w", stdout);

	std::cin >> N >> M >> C;
	cities.assign(N, 0);
	adj.assign(N, std::vector<int>());
	dp.assign(MAX_DAYS + 1, std::vector<int>(N, -1));

	for (int &x : cities)
		std::cin >> x;

	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B, --A, --B;

		adj[A].push_back(B);
	}

	dp[0][0] = 0;
	int ans = 0;

	for (int i = 0; i < MAX_DAYS; ++i) {
		for (int j = 0; j < N; ++j) {
			if (dp[i][j] == -1)
				continue;

			for (int u : adj[j])
				dp[i + 1][u] = std::max(dp[i + 1][u],
							dp[i][j] + cities[u]);
		}

		ans = std::max(ans, dp[i][0] - (C * i * i));
	}

	std::cout << ans << std::endl;

	return 0;
}
