#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		std::string s;
		std::cin >> s;

		std::cout << s[0] - '0' + s[2] - '0' << std::endl;
	}

	return 0;
}
