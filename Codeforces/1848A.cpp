#include <iostream>

int N, M, K;

void solve() {
	std::cin >> N >> M >> K;

	int X, Y;
	std::cin >> X >> Y;

	bool is_possible = 1;
	for (int i = 0; i < K; ++i) {
		int x, y;
		std::cin >> x >> y;

		if ((x + y) % 2 == (X + Y) % 2)
			is_possible = 0;
	}

	std::cout << (is_possible ? "YES" : "NO") << std::endl;
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
