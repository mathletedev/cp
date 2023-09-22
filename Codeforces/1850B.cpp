#include <iostream>

int N;

void solve() {
	std::cin >> N;

	std::pair<int, int> ans = {0, 0};
	for (int i = 1; i <= N; ++i) {
		int A, B;
		std::cin >> A >> B;

		if (A <= 10 && B > ans.first)
			ans = {B, i};
	}

	std::cout << ans.second << std::endl;
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
