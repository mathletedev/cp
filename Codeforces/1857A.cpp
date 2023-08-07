#include <iostream>

int N;

void solve() {
	std::cin >> N;

	int num_odd = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		std::cin >> A;

		if (A % 2 == 1)
			++num_odd;
	}

	std::cout << (num_odd % 2 == 0 ? "YES" : "NO") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
