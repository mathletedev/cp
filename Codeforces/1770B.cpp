#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n, k;
		std::cin >> n >> k;

		for (int i = 0; i < n; ++i) {
			if (i % 2 == 0)
				std::cout << n - i / 2 << " ";
			else
				std::cout << i / 2 + 1 << " ";
		}

		std::cout << std::endl;
	}

	return 0;
}
