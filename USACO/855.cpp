#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("mixmilk.in", "r", stdin);
	freopen("mixmilk.out", "w", stdout);

	std::vector<std::pair<int, int>> buckets;

	for (int i = 0; i < 3; ++i) {
		int c, m;
		std::cin >> c >> m;

		buckets.push_back({c, m});
	}

	for (int i = 0; i < 100; ++i) {
		int a, b;

		switch (i % 3) {
		case 0:
			a = 0;
			b = 1;
			break;
		case 1:
			a = 1;
			b = 2;
			break;
		case 2:
			a = 2;
			b = 0;
			break;
		}

		if (buckets[b].second + buckets[a].second <= buckets[b].first) {
			buckets[b].second += buckets[a].second;
			buckets[a].second = 0;
		} else {
			buckets[a].second -=
			    buckets[b].first - buckets[b].second;
			buckets[b].second = buckets[b].first;
		}
	}

	for (int i = 0; i < 3; ++i)
		std::cout << buckets[i].second << std::endl;

	return 0;
}
