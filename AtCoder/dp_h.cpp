#include <iostream>
#include <vector>

#define MOD 1000000007

int H, W;
std::vector<std::vector<char>> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> H >> W;
	A.assign(H + 1, std::vector<char>(W + 1));

	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j)
			std::cin >> A[i][j];
	}

	std::vector<std::vector<long long>> dp(
	    H + 1, std::vector<long long>(W + 1, 0));
	dp[1][1] = 1;

	for (int i = 1; i <= H; ++i) {
		for (int j = 1; j <= W; ++j) {
			if (A[i][j] == '#')
				continue;

			if (i < H) {
				dp[i + 1][j] += dp[i][j];
				dp[i + 1][j] %= MOD;
			}
			if (j < W) {
				dp[i][j + 1] += dp[i][j];
				dp[i][j + 1] %= MOD;
			}
		}
	}

	std::cout << dp[H][W] << std::endl;

	return 0;
}
