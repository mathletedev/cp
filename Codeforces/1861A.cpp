#include <iostream>

std::string S;

void solve() {
	std::cin >> S;

	bool one_first = 0;
	for (char c : S) {
		if (c == '1') {
			one_first = 1;
			break;
		}
		if (c == '3')
			break;
	}

	std::cout << (one_first ? 13 : 31) << std::endl;
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
