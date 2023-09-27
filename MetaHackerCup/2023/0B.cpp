#include <iostream>

int R, C, A, B;

void solve() {
	std::cin >> R >> C >> A >> B;

	std::cout << (R > C ? "YES" : "NO") << std::endl;
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
