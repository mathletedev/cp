#include <iostream>
#include <vector>

int N, K;
std::vector<int> H;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	H.assign(N, 0);

	for (int &x : H)
		std::cin >> x;

	std::vector<int> dp(N);
	dp[0] = 0;

	for (int i = 1; i < N; ++i) {
		int min = 1e9;
		for (int j = std::max(0, i - K); j < i; ++j)
			min = std::min(min, dp[j] + std::abs(H[i] - H[j]));

		dp[i] = min;
	}

	std::cout << dp[N - 1];

	return 0;
}
