#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

std::vector<std::vector<int>> subsets;

void gen(int m, int i = 0, std::vector<int> curr = {}) {
	if (i == m) {
		subsets.push_back(curr);
		return;
	}

	gen(m, i + 1, curr);

	curr.push_back(i);
	gen(m, i + 1, curr);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	std::vector<int> stalls(100);
	std::vector<std::tuple<int, int, int, int>> conditioners(m);

	for (int i = 0; i < n; ++i) {
		int s, t, c;
		std::cin >> s >> t >> c;

		for (int i = s - 1; i < t; ++i)
			stalls[i] = c;
	}

	for (int i = 0; i < m; ++i) {
		int a, b, p, m;
		std::cin >> a >> b >> p >> m;

		conditioners[i] = std::make_tuple(a - 1, b, p, m);
	}

	gen(m);

	int min = INT32_MAX;

	for (std::vector<int> set : subsets) {
		std::vector<int> tmp = stalls;
		int cost = 0;

		for (int i : set)
			cost += std::get<3>(conditioners[i]);

		if (cost >= min)
			continue;

		for (int i : set) {
			for (int j = std::get<0>(conditioners[i]);
			     j < std::get<1>(conditioners[i]); ++j)
				stalls[j] -= std::get<2>(conditioners[i]);
		}

		for (int i : stalls) {
			if (i > 0)
				goto next;
		}

		min = cost;

	next:;

		stalls = tmp;
	}

	std::cout << min << std::endl;

	return 0;
}
