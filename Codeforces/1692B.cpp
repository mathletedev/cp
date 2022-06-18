#include <iostream>
#include <set>

void solve() {
	int n;
	std::cin >> n;

	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];

	int d = std::set<int>(a, a + n).size();

	if (n % 2 != d % 2)
		d--;

	std::cout << d << std::endl;
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
