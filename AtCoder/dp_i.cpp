#include <iomanip>
#include <iostream>
#include <vector>

int N;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;

	std::vector<std::vector<double>> dp(N + 1,
					    std::vector<double>(N + 1, 0));

	double P;
	std::cin >> P;

	dp[1][0] = 1 - P;
	dp[1][1] = P;

	for (int i = 2; i <= N; ++i) {
		double P;
		std::cin >> P;

		for (int j = 0; j <= N; ++j) {
			dp[i][j] += dp[i - 1][j] * (1 - P);
			dp[i][j + 1] += dp[i - 1][j] * P;
		}
	}

	double ans = 0;
	for (int i = N / 2 + 1; i <= N; ++i)
		ans += dp[N][i];

	std::cout << std::setprecision(10) << ans << std::endl;

	return 0;
}
