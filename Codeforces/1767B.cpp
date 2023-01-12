#include <algorithm>
#include <cmath>
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

		int curr;
		std::cin >> curr;

		std::vector<int> a(n - 1);
		for (int i = 0; i < n - 1; ++i)
			std::cin >> a[i];

		std::sort(a.begin(), a.end());

		for (int i = 0; i < n - 1; ++i)
			if (a[i] > curr)
				curr += std::ceil((a[i] - curr) / 2.0);

		std::cout << curr << std::endl;
	}

	return 0;
}
