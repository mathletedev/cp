#include <iostream>

std::string A, B;

void solve() {
	std::cin >> A >> B;

	bool is_possible = 0;
	for (int i = 0; i < A.length() - 1; ++i) {
		if (A[i] == '0' && A[i + 1] == '1' && B[i] == '0' &&
		    B[i + 1] == '1') {
			is_possible = 1;
			break;
		}
	}

	std::cout << (is_possible ? "YES" : "NO") << std::endl;
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
