#include <iostream>

std::string S;

void solve() {
	std::cin >> S;

	for (int i = 1; i <= S.size() / 2 + S.size() % 2; ++i) {
		if (S[i] == '0')
			continue;

		std::string A = S.substr(0, i);
		std::string B = S.substr(i, S.size() - i);

		if (std::stoi(B) > std::stoi(A)) {
			std::cout << A << " " << B << std::endl;
			return;
		}
	}

	std::cout << -1 << std::endl;
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
