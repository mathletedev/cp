#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);

	int n, k;
	std::cin >> n >> k;

	std::string s[n];
	for (int i = 0; i < n; ++i)
		std::cin >> s[i];

	int c = 0;
	for (int i = 0; i < n - 1; ++i) {
		std::cout << s[i];
		c += s[i].length();

		if (c + s[i + 1].length() > k) {
			std::cout << std::endl;
			c = 0;
			continue;
		}

		std::cout << " ";
	}

	std::cout << s[n - 1] << std::endl;

	return 0;
}
