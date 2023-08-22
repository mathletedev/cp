#include <iostream>

std::string s;

void solve() {
	std::cin >> s;

	if (s == "()") {
		std::cout << "NO" << std::endl;
		return;
	}
	std::cout << "YES" << std::endl;

	bool has_double = 0;
	for (int i = 1; i < s.size(); ++i) {
		if (s[i] == s[i - 1])
			has_double = 1;
	}

	if (has_double) {
		for (int i = 0; i < s.size(); ++i)
			std::cout << "()";
		std::cout << std::endl;
	} else
		std::cout << std::string(s.size(), '(')
			  << std::string(s.size(), ')') << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
