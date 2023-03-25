#include <algorithm>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<int> t;
std::vector<std::vector<std::tuple<int, int, int>>> adj;
std::vector<int> a;
std::vector<int> k;

bool cmp(std::tuple<int, int, int> a, std::tuple<int, int, int> b) {
	return std::get<0>(a) > std::get<0>(b);
}

void dfs(int c, int r) {
	t[c] = std::min(t[c], r);

	while (k[c] < adj[c].size()) {
		std::tuple<int, int, int> f = adj[c][k[c]];
		if (std::get<0>(f) < r + a[c])
			break;

		++k[c];
		dfs(std::get<1>(f), std::get<2>(f));
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	adj = std::vector<std::vector<std::tuple<int, int, int>>>(n);
	for (int i = 0; i < m; ++i) {
		int c, r, d, s;
		std::cin >> c >> r >> d >> s;
		adj[c - 1].push_back({r, d - 1, s});
	}

	for (int i = 0; i < n; ++i)
		std::sort(adj[i].begin(), adj[i].end(), cmp);

	a = std::vector<int>(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];
	a[0] = 0;

	t = std::vector<int>(n, INT32_MAX);
	t[0] = 0;

	k = std::vector<int>(n, 0);
	dfs(0, 0);

	for (int x : t)
		std::cout << (x == INT32_MAX ? -1 : x) << std::endl;
}
