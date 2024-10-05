#include <iostream>

int N;

double solve() {
	std::cin >> N;

	double max_B = 0;
	double min_A = 1e9;

	for (int i = 1; i <= N; ++i) {
		double A, B;
		std::cin >> A >> B;

		max_B = std::max(max_B, i / B);
		min_A = std::min(min_A, i / A);
	}

	if (min_A < max_B) {
		return -1;
	}

	return max_B;
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
