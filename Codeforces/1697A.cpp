#include <algorithm>
#include <iostream>

void solve() {
	int n, m;
	std::cin >> n >> m;

	int t = 0;
	for (int i = 0; i < n; i++) {
		int d;
		std::cin >> d;
		t += d;
	}

	std::cout << std::max(t - m, 0) << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}
