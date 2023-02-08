#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, k;
	std::cin >> n >> k;

	std::vector<int> prefix(n, 0);

	while (k--) {
		int a, b;
		std::cin >> a >> b;

		++prefix[a - 1];
		--prefix[b];
	}

	std::vector<int> stacks(n, 0);
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += prefix[i];
		stacks[i] = sum;
	}

	std::sort(stacks.begin(), stacks.end());

	std::cout << stacks[n / 2] << std::endl;

	return 0;
}
