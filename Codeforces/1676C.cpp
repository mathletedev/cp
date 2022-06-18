#include <algorithm>
#include <cmath>
#include <iostream>

void solve() {
	int n, m;
	std::cin >> n >> m;

	char s[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> s[i][j];

	int b = INT32_MAX;

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			int d = 0;
			for (int k = 0; k < m; k++)
				d += std::abs(s[i][k] - s[j][k]);
			b = std::min(d, b);
		}
	}

	std::cout << b << std::endl;
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
