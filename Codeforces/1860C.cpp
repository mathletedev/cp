#include <iostream>
#include <vector>

int N;

void solve() {
	std::cin >> N;

	int prev_min = -1, prev_win = -1;
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int P;
		std::cin >> P;

		if (prev_min > P || prev_min == -1) {
			prev_min = P;
			continue;
		}

		if (prev_win > P || prev_win == -1)
			++ans, prev_win = P;
	}

	std::cout << ans << std::endl;
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
