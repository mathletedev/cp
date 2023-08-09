#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int N;
std::vector<long long> dp;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	dp.assign(N + 1, 0);

	dp[0] = 1;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= 6; ++j) {
			if (i - j >= 0)
				dp[i] += dp[i - j];
		}

		dp[i] %= MOD;
	}

	std::cout << dp[N] << std::endl;

	return 0;
}
