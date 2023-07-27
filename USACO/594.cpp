#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> haybales;

bool is_possible(int r) {
	int cows = 1, start = haybales[0];

	for (int pos : haybales) {
		if (pos - start <= 2 * r)
			continue;

		++cows;
		if (cows > K)
			return 0;

		start = pos;
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	std::cin >> N >> K;
	haybales.assign(N, 0);

	for (int &x : haybales)
		std::cin >> x;

	std::sort(haybales.begin(), haybales.end());

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
