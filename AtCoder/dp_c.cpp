#include <iostream>
#include <vector>

#define NUM_ACT 3

int N;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;

	std::vector<std::vector<int>> dp(N, std::vector<int>(NUM_ACT));
	for (int i = 0; i < N; ++i) {
		for (int &x : dp[i])
			std::cin >> x;
	}

	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < NUM_ACT; ++j) {
			int max = 0;
			for (int k = 0; k < NUM_ACT; ++k) {
				if (k != j)
					max = std::max(max, dp[i - 1][k]);
			}

			dp[i][j] += max;
		}
	}

	int ans = 0;
	for (int i = 0; i < NUM_ACT; ++i)
		ans = std::max(ans, dp[N - 1][i]);

	std::cout << ans << std::endl;

	return 0;
}
