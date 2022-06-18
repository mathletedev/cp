#include <iostream>

void solve() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	int t = 0;
	if (b > a)
		t++;
	if (c > a)
		t++;
	if (d > a)
		t++;

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
