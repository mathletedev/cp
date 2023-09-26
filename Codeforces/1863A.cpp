#include <iostream>

int N, A, Q;

void solve() {
	std::cin >> N >> A >> Q;

	int num_plus = 0, num_online = A;
	bool yes = 0;

	if (num_online >= N)
		yes = 1;

	for (int i = 0; i < Q; ++i) {
		char c;
		std::cin >> c;

		if (c == '+')
			++num_plus, ++num_online;
		else
			--num_online;

		if (num_online >= N)
			yes = 1;
	}

	if (yes)
		std::cout << "YES" << std::endl;
	else if (A + num_plus < N)
		std::cout << "NO" << std::endl;
	else
		std::cout << "MAYBE" << std::endl;
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
