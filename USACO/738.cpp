#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> cows;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int X, Y;
		std::cin >> X >> Y;

		cows.push_back({Y, X});
	}

	std::sort(cows.begin(), cows.end());

	int left = 0, right = N - 1;
	int max_time = 0;

	while (left < right) {
		max_time =
		    std::max(max_time, cows[left].first + cows[right].first);

		int num_low = cows[left].second;
		int num_high = cows[right].second;

		cows[left].second -= num_high;
		cows[right].second -= num_low;

		if (cows[left].second <= 0)
			++left;
		if (cows[right].second <= 0)
			--right;
	}

	if (cows[left].second > 0)
		max_time = std::max(max_time, cows[left].first * 2);

	std::cout << max_time << std::endl;

	return 0;
}
