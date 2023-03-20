#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::vector<std::tuple<int, int, int>>> graph;
std::vector<int> airports;
std::vector<int> dp;

void solve(int curr, int time) {
	dp[curr] = time;

	for (auto &t : graph[curr]) {
		if (std::get<0>(t) < time + airports[curr])
			continue;

		if (std::get<2>(t) < dp[std::get<1>(t)])
			solve(std::get<1>(t), std::get<2>(t));
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	graph = std::vector<std::vector<std::tuple<int, int, int>>>(n);
	airports = std::vector<int>(n);
	dp = std::vector<int>(n, INT32_MAX);

	for (int i = 0; i < n; ++i) {
		int c, r, d, s;
		std::cin >> c >> r >> d >> s;

		graph[c - 1].push_back({r, d - 1, s});
	}

	for (int i = 0; i < m; ++i)
		std::cin >> airports[i];

	solve(0, -airports[0]);
	dp[0] = 0;

	for (int t : dp)
		std::cout << (t == INT32_MAX ? -1 : t) << std::endl;

	return 0;
}
