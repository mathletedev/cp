#include <iostream>
#include <vector>

int N, X;
std::vector<int> C;
std::vector<int> dp;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> X;
	C.assign(N, 0);
	dp.assign(X + 1, 1e9);

	for (int &x : C)
		std::cin >> x;

	for (int c : C) {
		if (c <= X)
			dp[c] = 1;
	}

	for (int i = 0; i <= X; ++i) {
		if (dp[i] == 1e9)
			continue;

		for (int c : C) {
			if (i + c <= X)
				dp[i + c] = std::min(dp[i + c], dp[i] + 1);
		}
	}

	std::cout << (dp[X] == 1e9 ? -1 : dp[X]) << std::endl;

	return 0;
}
