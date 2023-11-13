#include <iostream>
#include <vector>

int N, W;
std::vector<int> weights, values;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> W;
	weights.assign(N, 0), values.assign(N, 0);

	for (int i = 0; i < N; ++i)
		std::cin >> weights[i] >> values[i];

	std::vector<std::vector<long long>> dp(
	    N + 1, std::vector<long long>(W + 1, -1));
	dp[0][0] = 0;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < W; ++j) {
			dp[i + 1][j] = std::max(dp[i + 1][j], dp[i][j]);

			if (dp[i][j] != -1 && j + weights[i] <= W)
				dp[i + 1][j + weights[i]] =
				    std::max(dp[i + 1][j + weights[i]],
					     dp[i][j] + values[i]);
		}
	}

	long long ans = 0;
	for (int i = 0; i <= W; ++i)
		ans = std::max(ans, dp[N][i]);

	std::cout << ans << std::endl;

	return 0;
}
