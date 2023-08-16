#include <iostream>

int N, K;

void solve() {
	std::cin >> N >> K;

	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		int a = i, b = N;

		for (int j = 0; j < K - 2; ++j) {
			int tmp = a;
			a = b - a;
			b = tmp;

			if (a > b || a < 0)
				goto next;
		}

		++ans;

	next:;
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
