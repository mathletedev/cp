#include <iostream>
#include <string>

void solve() {
	int s;
	std::cin >> s;

	std::string r = "";

	for (int i = 9; i >= 1; --i) {
		if (s <= 9 && s <= i) {
			std::cout << std::to_string(s) + r << std::endl;
			return;
		}
		s -= i;
		r = std::to_string(i) + r;
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
