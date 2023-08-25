#include <iostream>
#include <math.h>

long long N;

void solve() {
	std::cin >> N;

	long long x = (1 + sqrt(1 + 8 * N)) / 2;
	long long c = x * (x - 1) / 2;
	std::cout << x + (N - c) << std::endl;
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
