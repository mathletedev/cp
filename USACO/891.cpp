#include <cstdio>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("shell.in", "r", stdin);
	freopen("shell.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<std::tuple<int, int, int>> turns;

	for (int i = 0; i < n; ++i) {
		int a, b, g;
		std::cin >> a >> b >> g;

		turns.push_back(std::make_tuple(a, b, g));
	}

	int best = 0;

	for (int i = 1; i <= 3; ++i) {
		int curr = i;
		int count = 0;

		for (int r = 0; r < n; ++r) {
			if (curr == std::get<0>(turns[r]))
				curr = std::get<1>(turns[r]);
			else if (curr == std::get<1>(turns[r]))
				curr = std::get<0>(turns[r]);

			if (std::get<2>(turns[r]) == curr)
				++count;
		}

		best = std::max(best, count);
	}

	std::cout << best << std::endl;

	return 0;
}
