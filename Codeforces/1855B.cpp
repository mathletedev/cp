#include <iostream>

long long N;

void solve() {
	std::cin >> N;

	int i = 1;
	while (N % i == 0)
		++i;

	std::cout << i - 1 << std::endl;
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
