#include <algorithm>
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

		std::vector<int> a(n);
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];

		std::sort(a.begin(), a.end());

		int count = a[0] == 0 ? 0 : 1;

		for (int i = 0; i < n; ++i) {
			int same = a[i];
			while (i < n && a[i] == same)
				++i;

			if (i > 0)
				--i;
			if (a[i] <= i && (i == n - 1 || a[i + 1] > i + 1))
				++count;
		}

		std::cout << count << std::endl;
	}

	return 0;
}
