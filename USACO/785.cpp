#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<int> heights(n);
	for (int i = 0; i < n; ++i)
		std::cin >> heights[i];

	std::vector<int> sorted = heights;
	std::sort(sorted.begin(), sorted.end());

	int count = 0;
	for (int i = 0; i < n; ++i)
		count += sorted[i] != heights[i];

	std::cout << count - 1 << std::endl;

	return 0;
}
