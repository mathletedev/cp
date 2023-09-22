#include <iostream>
#include <vector>

int N;
std::vector<int> A, dp;

void solve() {
	std::cin >> N;
	A.assign(N + 1, 0), dp.assign(N + 1, 0);

	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;

		if (x <= N)
			++A[x];
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = i; j <= N; j += i)
			dp[j] += A[i];
	}

	int ans = 0;
	for (int x : dp)
		ans = std::max(ans, x);

	std::cout << ans << std::endl;
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
