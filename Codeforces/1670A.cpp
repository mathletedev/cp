#include <iostream>

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			std::cin >> a[i];

		bool y = true;
		int s = 0;

		for (int e : a)
			if (e < 0)
				s++;
		for (int i = 0; i < n; i++)
			a[i] = abs(a[i]) * (i < s ? -1 : 1);
		for (int i = 1; i < n; i++)
			if (a[i] < a[i - 1])
				y = false;

		std::cout << (y ? "YES" : "NO") << std::endl;
	}

	return 0;
}
