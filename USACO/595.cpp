#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<int> mod(7, -1);
	mod[0] = 0;
	int best = 0, rem = 0;

	for (int i = 1; i <= n; ++i) {
		int id;
		std::cin >> id;

		rem = (rem + id) % 7;

		if (mod[rem] == -1)
			mod[rem] = i;
		else
			best = std::max(best, i - mod[rem]);
	}

	std::cout << best << std::endl;

	return 0;
}
