#include <iostream>

void solve() {
	char b[8][8];
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			std::cin >> b[i][j];

	bool f = false;

	for (int i = 0; i < 8; i++) {
		int c = 0;
		int p = 0;
		for (int j = 0; j < 8; j++) {
			if (b[i][j] == '#') {
				c++;
				p = j;
			}
		}
		if (c == 1 && f) {
			std::cout << i + 1 << " " << p + 1 << std::endl;
			return;
		}
		if (c == 2)
			f = true;
	}
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
