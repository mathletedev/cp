#include <iostream>

int N;

void solve() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;
	}

	std::cout << (N % 2 == 0 ? 2 : 4) << std::endl;
	std::cout << "1 " << N / 2 * 2 << std::endl;
	std::cout << "1 " << N / 2 * 2 << std::endl;
	if (N % 2 == 1) {
		std::cout << N - 1 << " " << N << std::endl;
		std::cout << N - 1 << " " << N << std::endl;
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
