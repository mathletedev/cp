#include <iostream>

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	int min = 1e9;
	for (int i = 0; i < N; ++i) {
		int A;
		std::cin >> A;

		min = std::min(min, std::abs(A));
	}

	std::cout << min << std::endl;

	return 0;
}
