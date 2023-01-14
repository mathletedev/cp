#include <cmath>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n, a, b;
		std::cin >> n >> a >> b;

		if (a > b) {
			std::cout << 1 << std::endl;
			continue;
		}

		std::cout << std::fixed << (int)std::ceil((double)n / a)
			  << std::endl;
	}

	return 0;
}
