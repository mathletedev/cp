#include <cstdint>
#include <iostream>

int swap(int a, int mod, int min, int depth = 0) {
	if (depth >= min)
		return min;
	if (a % 2 != mod)
		return depth;
	return swap(a / 2, mod, min, depth + 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		int min = INT16_MAX, sum = 0;

		while (n--) {
			int a;
			std::cin >> a;

			sum += a;
			min = swap(a, a % 2, min);
		}

		std::cout << (sum % 2 == 0 ? 0 : min) << std::endl;
	}

	return 0;
}
