#include <algorithm>
#include <cstdint>
#include <iostream>

void solve() {
	int n;
	std::cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int m = INT32_MAX;
	for (int e : a)
		m = std::min(e, m);

	int t = 0;
	for (int e : a)
		t += e - m;

	std::cout << t << std::endl;
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
