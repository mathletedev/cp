#include <iostream>

long long N, M;

void solve() {
	std::cin >> N >> M;

	N %= M;

	if (N == 0) {
		std::cout << 0 << std::endl;
		return;
	}

	long long ans = 0;
	int count = 0;

	while (N != 0) {
		ans += N;
		N *= 2;
		N %= M;

		if (++count > 1000) {
			ans = -1;
			break;
		}
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
