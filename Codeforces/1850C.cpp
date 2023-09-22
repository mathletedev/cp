#include <iostream>

void solve() {
	std::string ans = "";
	for (int i = 0; i < 64; ++i) {
		char c;
		std::cin >> c;

		if (c != '.')
			ans += c;
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
