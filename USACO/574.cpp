#include <cstdio>
#include <iostream>
#include <vector>

int T, A, B;
std::vector<std::vector<bool>> dp;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);

	std::cin >> T >> A >> B;
	dp.assign(2, std::vector<bool>(T + 1));

	dp[0][0] = 1;

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < T; ++j) {
			if (!dp[i][j])
				continue;

			if (j + A <= T)
				dp[i][j + A] = 1;
			if (j + B <= T)
				dp[i][j + B] = 1;

			if (i == 0)
				dp[1][j / 2] = 1;
		}
	}

	int ans = T;
	while (!dp[1][ans])
		--ans;

	std::cout << ans << std::endl;

	return 0;
}
