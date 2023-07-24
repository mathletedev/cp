#include <iostream>
#include <ostream>

int N;

int greedy(long long a, long long b) {
	if (a == b)
		return 0;
	if (a > b)
		return 1 + a % 2 + greedy((a + a % 2) / 2, b);
	else
		return std::min(b - a, 1 + b % 2 + greedy(a, b / 2));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;

	while (N--) {
		long long A, B;
		std::cin >> A >> B;

		std::cout << greedy(A, B) << std::endl;
	}

	return 0;
}
