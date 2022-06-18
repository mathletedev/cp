#include <iomanip>
#include <iostream>

void solve() {
	int n;
	std::cin >> n;

	int s[n];
	for (int i = 0; i < n; i++)
		std::cin >> s[i];
	int f[n];
	for (int i = 0; i < n; i++)
		std::cin >> f[i];

	int d[n];

	for (int i = 0; i < n; i++) {
		int l = 0;
		if (i > 0)
			l = f[i - 1];
		d[i] = f[i] - (s[i] > l ? s[i] : l);
	}

	for (int e : d)
		std::cout << e << " ";
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
