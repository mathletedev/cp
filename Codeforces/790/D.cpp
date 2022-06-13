#include <algorithm>
#include <iostream>

void solve() {
	int n, m;
	std::cin >> n >> m;

	int c[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			std::cin >> c[i][j];

	int b = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int t = 0;
			int di = 0, dj = 0;
			if (i > j)
				di = i - j;
			else
				dj = j - i;
			for (int k = 0; k + di < n && k + dj < m; k++)
				t += c[k + di][k + dj];
			di = 0;
			dj = 0;
			if (i > m - j - 1)
				di = i - (m - j - 1);
			else
				dj = m - j - 1 - i;
			for (int k = 0; k + di < n && m - k - dj - 1 >= 0; k++)
				t += c[k + di][m - k - dj - 1];
			t -= c[i][j];
			b = std::max(t, b);
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
