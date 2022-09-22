#include <iostream>

void solve() {
	int n;
	std::cin >> n;

	std::cout << n << " ";
	for (int i = 1; i < n; ++i)
		std::cout << i << " ";

	std::cout << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--)
		solve();

	return 0;
}
