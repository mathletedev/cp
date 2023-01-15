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

		int q = 0, a = 0;

		for (int i = n - 1; i >= 0; --i) {
			if (s[i] == 'Q')
				++q;
			else
				++a;

			if (q > a) {
				std::cout << "No" << std::endl;
				goto skip;
			}
		}

		std::cout << "Yes" << std::endl;
		continue;

	skip:;
	}

	return 0;
}
