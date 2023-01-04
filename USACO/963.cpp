#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int indexOf(std::vector<int> vector, int value) {
	return std::find(vector.begin(), vector.end(), value) - vector.begin();
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("gymnastics.in", "r", stdin);
	freopen("gymnastics.out", "w", stdout);

	int k, n;
	std::cin >> k >> n;

	std::vector<std::vector<int>> sessions;

	while (k--) {
		std::vector<int> rankings;
		for (int i = 0; i < n; ++i) {
			int x;
			std::cin >> x;
			rankings.push_back(x);
		}
		sessions.push_back(rankings);
	}

	int count = 0;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;

			for (std::vector<int> s : sessions) {
				if (indexOf(s, i) < indexOf(s, j))
					goto worse;
			}

			++count;
		worse:;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
