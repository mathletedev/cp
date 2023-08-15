#include <algorithm>
#include <iostream>

int recurse(int b, int e, int a[], int s, int t, int d = 0) {
	if (t == s)
		return d;
	if (b == e)
		return -1;

	int n = recurse(b + 1, e, a, s, a[b] == 1 ? t - 1 : t, d + 1);
	int m = recurse(b, e - 1, a, s, a[e] == 1 ? t - 1 : t, d + 1);

	if (n == -1 && m == -1)
		return -1;
	if (n == -1)
		return m;
	if (m == -1)
		return n;
	return std::min(n, m);
}

void solve() {
	int n, s;
	std::cin >> n >> s;

	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int t = 0;
	for (int i = 0; i < n; i++)
		t += a[i];

	std::cout << recurse(0, n - 1, a, s, t) << std::endl;
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
