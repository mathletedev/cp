#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		std::cout << n / 2 + n % 2 << std::endl;

		int i = 1, j = n * 3;
		while (i < j) {
			std::cout << i << " " << j << std::endl;
			i += 3;
			j -= 3;
		}
	}

	return 0;
}
