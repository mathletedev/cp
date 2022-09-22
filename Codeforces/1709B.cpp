#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	int f[n - 1];
	for (int i = 1; i < n; ++i)
		f[i] = a[i] < a[i - 1] ? a[i - 1] - a[i] : 0;

	int b[n - 1];
	for (int i = n - 2; i >= 0; --i)
		b[i] = a[i] < a[i + 1] ? a[i + 1] - a[i] : 0;

	while (m--) {
		int s, t;
		std::cin >> s >> t;

		int d = 0;

		if (s < t)
			for (int j = s; j < t; ++j)
				d += f[j];
		else
			for (int j = s - 2; j >= t - 1; --j)
				d += b[j];

		std::cout << d << std::endl;
	}

	return 0;
}
