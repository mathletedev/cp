#include <algorithm>
#include <iostream>
#include <vector>

int N, K, B;
std::vector<int> signals;

bool is_possible(int x) {
	for (int i = 0; i < B - x + 1; ++i) {
		int left = (i == 0 ? 1 : signals[i - 1]);
		int right = (i + x == B ? N : signals[i + x]);

		if (right - left >= K)
			return 1;
	}

	return 0;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	std::cin >> N >> K >> B;
	signals.assign(B, 0);

	for (int &x : signals)
		std::cin >> x;

	std::sort(signals.begin(), signals.end());

	int low = 0, high = B;
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
