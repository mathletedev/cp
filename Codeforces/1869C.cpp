#include <iostream>

int N, M;

void solve() {
	std::cin >> N >> M;

	std::cout << (M == 1 ? 0 : std::min(N + 1, M)) << std::endl;

	int offset = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cout << (j + offset) % M << " ";
		}
		std::cout << std::endl;

		if (offset < M - 2)
			++offset;
	}
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
