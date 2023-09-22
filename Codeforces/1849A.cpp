#include <iostream>

int B, C, H;

void solve() {
	std::cin >> B >> C >> H;

	std::cout << std::min(B - 1, C + H) * 2 + 1 << std::endl;
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
