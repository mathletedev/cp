#include <iostream>

int N, K, X;

void solve() {
	std::cin >> N >> K >> X;

	if (K > N || X < K - 1) {
		std::cout << -1 << std::endl;
		return;
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (i < K)
			ans += i;
		else if (K == X)
			ans += K - 1;
		else
			ans += X;
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
