#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int N, M, C;
std::vector<int> cows;

bool is_possible(int t) {
	int buses = 0, seats = 0, wait_time = 0;

	for (int i = 0; i < N; ++i) {
		++seats;

		if (seats > C || cows[i] - wait_time > t || i == 0) {
			++buses;
			if (buses > M)
				return 0;

			seats = 1;
			wait_time = cows[i];
		}
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	std::cin >> N >> M >> C;
	cows.assign(N, 0);

	for (int &x : cows)
		std::cin >> x;
	std::sort(cows.begin(), cows.end());

	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high) / 2;

		if (is_possible(mid))
			high = mid;
		else
			low = mid + 1;
	}

	std::cout << low << std::endl;

	return 0;
}
