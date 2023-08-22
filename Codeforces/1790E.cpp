#include <iostream>

int X;

void solve() {
	std::cin >> X;

	if (X % 2 == 1) {
		std::cout << -1 << std::endl;
		return;
	}

	int a = X / 2, b = X / 2;
	if (a & X) {
		std::cout << -1 << std::endl;
		return;
	}

	std::cout << a + X << " " << b << std::endl;
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
