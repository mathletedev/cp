#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int q;
	std::cin >> q;

	while (q--) {
		std::string s;
		std::cin >> s;

		if (s.length() < 3) {
			std::cout << -1 << std::endl;
			goto next;
		}

		for (int i = 0; i < s.length() - 2; ++i) {
			if (s[i] == 'M' && s[i + 1] == 'O' && s[i + 2] == 'O') {
				std::cout << s.length() - 3 << std::endl;
				goto next;
			}
		}

		for (int i = 1; i < s.length() - 1; ++i) {
			if (s[i] == 'O' && s[i + 1] == 'O') {
				std::cout << s.length() - 2 << std::endl;
				goto next;
			}
		}

		for (int i = 0; i < s.length() - 2; ++i) {
			if (s[i] == 'M' && s[i + 1] == 'O') {
				std::cout << s.length() - 2 << std::endl;
				goto next;
			}
		}

		for (int i = 1; i < s.length() - 1; ++i) {
			if (s[i] == 'O') {
				std::cout << s.length() - 1 << std::endl;
				goto next;
			}
		}

		std::cout << -1 << std::endl;

	next:;
	}

	return 0;
}
