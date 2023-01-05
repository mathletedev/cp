#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("herding.in", "r", stdin);
	freopen("herding.out", "w", stdout);

	std::vector<int> pos(3);
	std::cin >> pos[0] >> pos[1] >> pos[2];
	std::sort(pos.begin(), pos.end());
	int a = pos[0], b = pos[1], c = pos[2];

	int min = 2, max;

	if (a == b - 2 || b == c - 2)
		min = 1;
	if (a == b - 1 && b == c - 1)
		min = max = 0;
	else {
		if (b - a < c - b)
			max = c - b - 1;
		else
			max = b - a - 1;
	}

	std::cout << min << "\n" << max << std::endl;

	return 0;
}
