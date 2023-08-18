#include <iostream>

int N, M;

void solve() {
	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::cout
			    << 1 + j + (i / 2 + (i % 2 == 0 ? N / 2 : 0)) * M
			    << " ";
		}
		std::cout << std::endl;
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
