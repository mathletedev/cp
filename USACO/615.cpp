#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("pails.in", "r", stdin);
	freopen("pails.out", "w", stdout);

	int x, y, m;
	std::cin >> x >> y >> m;

	int best = 0;

	for (int i = 0; i <= m; i += x) {
		for (int j = 0; j + i <= m; j += y) {
			best = std::max(best, i + j);
		}
	}

	std::cout << best << std::endl;

	return 0;
}
