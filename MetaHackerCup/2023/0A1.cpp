#include <iostream>

int S, D, K;

void solve() {
	std::cin >> S >> D >> K;

	std::cout << (S + D * 2 >= K && S * 2 + D * 2 >= K + 1 ? "YES" : "NO")
		  << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
