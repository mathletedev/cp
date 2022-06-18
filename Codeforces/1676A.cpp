#include <iostream>

void solve() {
	char t[6];
	std::cin >> t;

	int a = 0, b = 0;
	for (int i = 0; i < 3; i++)
		a += t[i] - '0';
	for (int i = 3; i < 6; i++)
		b += t[i] - '0';

	std::cout << (a == b ? "YES" : "NO") << std::endl;
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
