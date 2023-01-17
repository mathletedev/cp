#include <cmath>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n, k;
		std::cin >> n >> k;

		int curr = 1;
		for (int i = 0; i < n; ++i) {
			int p;
			std::cin >> p;

			if (p == curr)
				++curr;
		}

		std::cout << (int)std::ceil(double(n - curr + 1) / k)
			  << std::endl;
	}

	return 0;
}
