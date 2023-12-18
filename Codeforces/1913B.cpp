#include <iostream>

std::string S;

void solve() {
	std::cin >> S;
	int N = S.size();

	int zeros = 0;
	int ones = 0;
	for (char c : S) {
		if (c == '0')
			++zeros;
		else
			++ones;
	}

	char target;
	if (ones > zeros)
		target = '0';
	else
		target = '1';

	int count = 0;
	int ans = N;
	for (int i = 0; i < N; ++i) {
		if (S[i] == target)
			++count;
		if (std::abs(std::max(zeros, ones) - count) <= N - (i + 1))
			ans = N - (i + 1);
	}

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
