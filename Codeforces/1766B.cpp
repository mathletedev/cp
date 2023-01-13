#include <iostream>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::string s;
		std::cin >> n >> s;

		std::unordered_set<std::string> subs;
		std::string prev = "";
		bool found = false;

		for (int i = 0; i < n - 1; ++i) {
			std::string sub = s.substr(i, 2);
			if (subs.count(sub)) {
				found = true;
				break;
			}

			subs.insert(prev);
			prev = sub;
		}

		std::cout << (found ? "YES" : "NO") << std::endl;
	}

	return 0;
}
