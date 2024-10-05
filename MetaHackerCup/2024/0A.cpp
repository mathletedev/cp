#include <iostream>

using ll = long long;

ll N, K;

std::string solve() {
	std::cin >> N >> K;

	ll min = 1e9;
	for (int i = 0; i < N; ++i) {
		ll Si;
		std::cin >> Si;

		min = std::min(min, Si);
	}

	if (min * std::max<ll>(1, 2 * (N - 1) - 1) <= K) {
		return "YES";
	}

	return "NO";
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": " << solve() << std::endl;
	}

	return 0;
}
