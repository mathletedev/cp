#include <iostream>
#include <vector>

int N;
std::vector<int> bosses;

void solve() {
	std::cin >> N;
	bosses.assign(N, 0);

	for (int &x : bosses)
		std::cin >> x;

	std::vector<std::vector<int>> dp(2, std::vector<int>(N + 1, 1e9));

	dp[1][0] = 0;

	for (int i = 0; i < N; ++i) {
		dp[0][i + 1] = std::min(dp[0][i + 1], dp[1][i] + bosses[i]);
		dp[1][i + 1] = std::min(dp[1][i + 1], dp[0][i]);

		if (i + 2 <= N) {
			dp[0][i + 2] = std::min(
			    dp[0][i + 2], dp[1][i] + bosses[i] + bosses[i + 1]);
			dp[1][i + 2] = std::min(dp[1][i + 2], dp[0][i]);
		}
	}

	std::cout << std::min(dp[0][N], dp[1][N]) << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
