#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> cows(n, std::vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			char c;
			std::cin >> c;
			cows[i][j] = c == '0' ? 0 : 1;
		}
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(n));

	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1; j >= 0; --j) {
			if (dp[i][j] % 2 != cows[i][j]) {
				for (int k = 0; k <= i; ++k) {
					for (int l = 0; l <= j; ++l)
						++dp[k][l];
				}
			}
		}
	}

	std::cout << dp[0][0] << std::endl;

	return 0;
}
