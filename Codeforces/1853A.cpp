#include <iostream>

int N;

void solve() {
	std::cin >> N;

	int prev;
	std::cin >> prev;

	int ans = 1e9;
	for (int i = 1; i < N; ++i) {
		int A;
		std::cin >> A;

		int diff = A - prev;
		if (diff < 0)
			diff = -1e9;
		ans = std::min(ans, diff / 2 + 1);

		prev = A;
	}

	std::cout << std::max(0, ans) << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
