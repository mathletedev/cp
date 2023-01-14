#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		long long count = 0;
		for (int i = 0; i < n; ++i) {
			int a;
			std::cin >> a;
			count += a;
		}

		int max = 0;
		for (int i = 0; i < n; ++i) {
			int b;
			std::cin >> b;
			max = std::max(max, b);
			count += b;
		}

		std::cout << count - max << std::endl;
	}

	return 0;
}
