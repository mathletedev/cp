#include <iostream>

void solve() {
	int n;
	std::cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	int b[n];
	for (int i = 0; i < n; i++)
		std::cin >> b[i];

	int d = -1;

	for (int i = 0; i < n; i++) {
		if (a[i] - b[i] < 0) {
			std::cout << "NO" << std::endl;
			return;
		}
		if (b[i] == 0)
			continue;
		if (d == -1)
			d = a[i] - b[i];
		if (a[i] - b[i] != d) {
			std::cout << "NO" << std::endl;
			return;
		}
	}

	for (int i = 0; i < n; i++) {
		if (b[i] > 0)
			continue;
		if (a[i] > d && d > -1) {
			std::cout << "NO" << std::endl;
			return;
		}
	}

	std::cout << "YES" << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}
