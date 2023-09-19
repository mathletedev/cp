#include <iostream>
#include <vector>

int N, K;
std::vector<int> C;

void solve() {
	std::cin >> N >> K;
	C.assign(N, 0);

	for (int &x : C)
		std::cin >> x;

	if (C[0] == C[N - 1]) {
		int num = 0;
		for (int x : C) {
			if (x == C[0])
				++num;
		}

		std::cout << (num >= K ? "YES" : "NO") << std::endl;
		return;
	}

	int left = 0, right = N - 1;
	for (int i = 0; i < K - 1; ++i) {
		++left;
		while (left < N - 1 && C[left] != C[0])
			++left;

		--right;
		while (right > 0 && C[right] != C[N - 1])
			--right;
	}

	std::cout << (left < right ? "YES" : "NO") << std::endl;
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
