#include <iostream>

int A, B, C;

void solve() {
	std::cin >> A >> B >> C;

	if (C % 2 == 0)
		std::cout << (A > B ? "First" : "Second") << std::endl;
	else
		std::cout << (B > A ? "Second" : "First") << std::endl;
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
