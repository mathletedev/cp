#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);

	int n, k;
	std::cin >> n >> k;

	std::vector<std::vector<int>> plane(1000, std::vector<int>(1000));

	while (n--) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;

		for (int i = y1; i < y2; ++i) {
			++plane[i][x1];
			--plane[i][x2];
		}
	}

	int count = 0, curr = 0;

	for (int i = 0; i < 1000; ++i) {
		for (int j = 0; j < 1000; ++j) {
			curr += plane[i][j];
			count += curr == k;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
