#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::string s;
		std::cin >> n >> s;

		if (n % 3 == 2) {
			std::cout << "NO" << std::endl;
			continue;
		}

		for (int i = 1; i < n; i += 3) {
			if (s[i] != s[i + 1]) {
				std::cout << "NO" << std::endl;
				goto skip;
			}
		}

		std::cout << "YES" << std::endl;

	skip:;
	}

	return 0;
}
