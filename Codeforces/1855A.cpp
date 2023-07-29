#include <iostream>

int N;

void solve() {
	std::cin >> N;

	int num_same = 0;
	for (int i = 0; i < N; ++i) {
		int P;
		std::cin >> P;

		if (P - 1 == i)
			++num_same;
	}

	std::cout << num_same / 2 + num_same % 2 << std::endl;
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
