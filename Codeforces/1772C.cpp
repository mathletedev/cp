#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int k, n;
		std::cin >> k >> n;

		int curr = 1;

		for (int i = 1; i < k; ++i) {
			std::cout << curr << " ";

			curr += curr + k - 1 > n ? 1 : i;
		}

		std::cout << curr << std::endl;
	}

	return 0;
}
