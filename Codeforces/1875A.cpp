#include <iostream>

long long A, B, N;

void solve() {
	std::cin >> A >> B >> N;

	long long ans = B;
	for (int i = 0; i < N; ++i) {
		long long x;
		std::cin >> x;

		ans += std::min(x, A - 1);
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
