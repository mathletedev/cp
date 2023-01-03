#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("blocks.in", "r", stdin);
	freopen("blocks.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<int> blocks(26, 0);

	while (n--) {
		std::string a, b;
		std::cin >> a >> b;

		std::vector<int> aCount(26, 0);
		std::vector<int> bCount(26, 0);

		for (char &c : a)
			++aCount[c - 'a'];
		for (char &c : b)
			++bCount[c - 'a'];

		for (int i = 0; i < 26; ++i)
			blocks[i] += std::max(aCount[i], bCount[i]);
	}

	for (int b : blocks)
		std::cout << b << std::endl;

	return 0;
}
