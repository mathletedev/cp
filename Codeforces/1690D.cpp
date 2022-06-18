#include <algorithm>
#include <iostream>

void solve() {
	int n, k;
	std::cin >> n >> k;

	char s[n];
	for (int i = 0; i < n; i++)
		std::cin >> s[i];

	int c = 0;
	for (int i = 0; i < k; i++)
		if (s[i] == 'W')
			c++;
	int b = c;

	for (int i = 0; i < n - k; i++) {
		if (s[i] == 'W')
			c--;
		if (s[i + k] == 'W')
			c++;

		b = std::min(c, b);
		if (b == 0) {
			std::cout << 0 << std::endl;
			return;
		}
	}

	std::cout << b << std::endl;
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
