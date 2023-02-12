#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, x;
	std::cin >> n >> x;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i)
		std::cin >> a[i];

	std::sort(a.begin(), a.end());

	int i = 0, acc = 0;
	for (; i < n; ++i) {
		acc += a[i];
		if (acc > x)
			break;
	}

	std::cout << i << std::endl;

	return 0;
}
