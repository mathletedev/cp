#include <iostream>

std::string S;

void solve() {
	std::cin >> S;

	if (S.length() != 1 && S[S.length() - 1] == '0')
		std::cout << "E" << std::endl;
	else
		std::cout << "B" << std::endl;
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
