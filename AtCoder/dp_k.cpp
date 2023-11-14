#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::vector<bool> dp(K + 1, 0);

	for (int i = 1; i <= K; ++i) {
		for (int x : A) {
			if (i >= x && !dp[i - x])
				dp[i] = 1;
		}
	}

	std::cout << (dp[K] ? "First" : "Second") << std::endl;

	return 0;
}
