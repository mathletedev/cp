#include <iostream>
#include <set>

void solve() {
	int n;
	std::cin >> n;

	int a[n];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::set<int> s;

	for (int i = n - 1; i >= 0; --i) {
		if (s.find(a[i]) != s.end()) {
			std::cout << i + 1 << std::endl;
			return;
		}
		s.insert(a[i]);
	}

	std::cout << 0 << std::endl;
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
