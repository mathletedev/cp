#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("speeding.in", "r", stdin);
	freopen("speeding.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> targets, real;

	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;

		for (int j = 0; j < a; ++j)
			targets.push_back(b);
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		std::cin >> a >> b;

		for (int j = 0; j < a; ++j)
			real.push_back(b);
	}

	int max = 0;

	for (int i = 0; i < 100; ++i)
		max = std::max(max, real[i] - targets[i]);

	std::cout << max << std::endl;

	return 0;
}
