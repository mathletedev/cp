#include <iostream>

int N;

void solve() {
	int N;
	std::cin >> N;

	int S, E;
	std::cin >> S >> E;

	bool is_possible = 1;
	for (int i = 0; i < N - 1; ++i) {
		int s, e;
		std::cin >> s >> e;

		if (s >= S && e >= E)
			is_possible = 0;
	}

	std::cout << (is_possible ? S : -1) << std::endl;
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
