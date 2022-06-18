#include <iostream>

void solve() {
	int x;
	std::cin >> x;

	int n = 0;
	while (true) {
		if ((n & x) > 0 && (n ^ x) > 0) {
			std::cout << n << std::endl;
			return;
		}
		n++;
	}
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
