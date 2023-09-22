#include <iostream>

int A, B, C;

void solve() {
	std::cin >> A >> B >> C;

	std::cout << (A + B >= 10 || B + C >= 10 || A + C >= 10 ? "YES" : "NO")
		  << std::endl;
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
