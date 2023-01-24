#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n, m;
		std::cin >> n >> m;

		std::vector<long long> a(n), b(m);
		for (int i = 0; i < n; ++i)
			std::cin >> a[i];
		for (int i = 0; i < m; ++i)
			std::cin >> b[i];

		std::sort(a.begin(), a.end());

		for (int i = 0; i < m; ++i) {
			a[0] = b[i];
			std::sort(a.begin(), a.end());
		}

		long long sum = 0;
		for (long long i : a)
			sum += i;

		std::cout << sum << std::endl;
	}

	return 0;
}
