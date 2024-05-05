#include <iostream>
#include <map>
#include <vector>

int N, Q, C;

void solve() {
	std::cin >> N >> Q >> C;
	std::vector<int> cows(N);
	std::map<int, int> pairs;

	for (int &x : cows)
		std::cin >> x;
	for (int i = 0; i < Q; ++i) {
		int A, H;
		std::cin >> A >> H;
		--A, --H;

		pairs[A] = H;
	}

	std::vector<bool> edit(N);
	for (int i = 0; i < N; ++i)
		if (cows[i] == 0)
			edit[i] = 1;

	std::vector<int> prefix(N + 1);
	prefix[0] = 0;
	for (int i = 0; i < N; ++i) {
		if (cows[i] == 0)
			cows[i] = 1;

		prefix[i + 1] = std::max(prefix[i], cows[i]);

		if (pairs[i]) {
			if (edit[pairs[i]])
				cows[pairs[i]] = prefix[i + 1] + 1;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (!pairs[i] || !edit[i])
			continue;

		if (prefix[pairs[i]] > prefix[i])
			cows[i] = prefix[pairs[i]];
	}

	for (int i = 0; i < N; ++i)
		prefix[i + 1] = std::max(prefix[i], cows[i]);

	for (int i = 0; i < N; ++i) {
		if (cows[i] > C) {
			std::cout << -1 << std::endl;
			return;
		}

		if (pairs[i] && prefix[pairs[i]] > prefix[i + 1]) {
			std::cout << -1 << std::endl;
			return;
		}
	}

	std::cout << cows[0];
	for (int i = 1; i < cows.size(); ++i)
		std::cout << " " << cows[i];
	std::cout << std::endl;
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
