#include <iostream>

void solve() {
	int h, m, x;
	char z;
	std::cin >> h >> z >> m >> x;

	int t = h * 60 + m;
	int c = 0;

	for (int i = 0; i < 24; i++) {
		if ((i > 5 && i < 10) || (i > 15 && i < 20))
			continue;

		int a = i * 60 + ((i % 60) % 10) * 10 + (i % 60) / 10;
		if ((a - t) % x == 0)
			c++;
	}

	std::cout << c << std::endl;
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
