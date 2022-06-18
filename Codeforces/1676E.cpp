#include <algorithm>
#include <functional>
#include <iostream>

void query(int n, int a[]) {
	int x;
	std::cin >> x;

	int l = 0, h = n - 1;
	while (h >= l) {
		int m = (h + l) / 2;
		if (a[m] >= x)
			h = m - 1;
		else
			l = m + 1;
	}

	std::cout << (l == n ? -1 : l + 1) << std::endl;
}

void solve() {
	int n, q;
	std::cin >> n >> q;

	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	std::sort(a, a + n, std::greater<int>());

	int t = 0;
	for (int i = 0; i < n; i++) {
		t += a[i];
		a[i] = t;
	}

	while (q--)
		query(n, a);
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
