#include <iostream>
#include <map>

int N;

void solve() {
	std::cin >> N;

	std::map<int, long long> horizontal, vertical, diagonal1, diagonal2;
	for (int i = 0; i < N; ++i) {
		int X, Y;
		std::cin >> X >> Y;

		++horizontal[X];
		++vertical[Y];
		++diagonal1[Y - X];
		++diagonal2[Y + X];
	}

	long long ans = 0;
	for (std::pair<int, long long> p : horizontal)
		ans += p.second * (p.second - 1);
	for (std::pair<int, long long> p : vertical)
		ans += p.second * (p.second - 1);
	for (std::pair<int, long long> p : diagonal1)
		ans += p.second * (p.second - 1);
	for (std::pair<int, long long> p : diagonal2)
		ans += p.second * (p.second - 1);

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
