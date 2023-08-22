#include <iostream>
#include <ostream>

int N, X;
long long Y;

void solve() {
	std::cin >> N >> X >> Y;

	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		int A;
		std::cin >> A;

		sum += A;
	}

	std::cout << ((X + sum) % 2 == Y % 2 ? "Alice" : "Bob") << std::endl;
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
