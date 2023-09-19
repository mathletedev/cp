#include <iostream>

int N, M, K, H;

void solve() {
	std::cin >> N >> M >> K >> H;

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;

		int diff = std::abs(H - x);
		if (diff != 0 && diff % K == 0 && diff / K < M)
			++ans;
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
