#include <algorithm>
#include <iostream>

int N;

void solve() {
	std::cin >> N;

	long long ans = 0;
	int sac = 1e9, rep = 1e9;
	for (int i = 0; i < N; ++i) {
		int M;
		std::cin >> M;

		int min1 = 1e9, min2 = 1e9;
		for (int j = 0; j < M; ++j) {
			int A;
			std::cin >> A;

			if (A < min1)
				min2 = min1, min1 = A;
			else if (A < min2)
				min2 = A;
		}

		ans += min2;

		sac = std::min(sac, min1);
		rep = std::min(rep, min2);
	}

	ans += sac - rep;

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
