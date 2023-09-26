#include <iostream>
#include <vector>

int N;
std::vector<int> P;

void solve() {
	std::cin >> N;
	P.assign(N + 1, 0);

	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;
		P[x] = i;
	}

	int ans = 0;
	for (int x = 1; x < N; ++x) {
		if (P[x] > P[x + 1])
			++ans;
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
