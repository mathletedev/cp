#include <iostream>
#include <vector>

int N;
std::vector<int> H;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	H.assign(N, 0);

	for (int &x : H)
		std::cin >> x;

	std::vector<int> dp(N);
	dp[0] = 0;
	dp[1] = std::abs(H[1] - H[0]);

	for (int i = 2; i < N; ++i)
		dp[i] = std::min(dp[i - 1] + std::abs(H[i] - H[i - 1]),
				 dp[i - 2] + std::abs(H[i] - H[i - 2]));

	std::cout << dp[N - 1];

	return 0;
}
