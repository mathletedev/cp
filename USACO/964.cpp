#include <cstdio>
#include <iostream>
#include <unordered_set>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("whereami.in", "r", stdin);
	freopen("whereami.out", "w", stdout);

	int n;
	std::string m;
	std::cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		std::unordered_set<std::string> seen;
		for (int j = 0; j < n - i + 1; ++j) {
			std::string sub = m.substr(j, i);
			if (seen.count(sub))
				goto found;
			seen.insert(sub);
		}

		std::cout << i << std::endl;
		return 0;

	found:
		continue;
	}

	return 0;
}
