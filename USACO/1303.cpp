#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

long long square(long long x) { return x * x; }
bool comp(std::tuple<long long, long long, long long> a,
	  std::tuple<long long, long long, long long> b) {
	return std::get<2>(a) < std::get<2>(b);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int g, n;
	std::cin >> g >> n;

	std::vector<std::tuple<long long, long long, long long>> grazings(g);
	std::vector<std::tuple<long long, long long, long long>> alibis(g);

	for (int i = 0; i < g; ++i) {
		int x, y, t;
		std::cin >> x >> y >> t;

		grazings[i] = {x, y, t};
	}

	for (int i = 0; i < n; ++i) {
		int x, y, t;
		std::cin >> x >> y >> t;

		alibis[i] = {x, y, t};
	}

	std::sort(grazings.begin(), grazings.end(), comp);

	int count = 0;

	for (int i = 0; i < n; ++i) {
		int t = std::get<2>(alibis[i]);
		int l = 0, h = g - 1;

		for (int d = h; d > 0; d /= 2) {
			while (l + d <= h && std::get<2>(grazings[l + d]) <= t)
				l += d;
		}

		if (square(std::get<0>(alibis[i]) - std::get<0>(grazings[l])) +
			square(std::get<1>(alibis[i]) -
			       std::get<1>(grazings[l])) >
		    square(std::get<2>(alibis[i]) - std::get<2>(grazings[l])))
			++count;
		else if (l < g - 1 &&
			 square(std::get<0>(alibis[i]) -
				std::get<0>(grazings[l + 1])) +
				 square(std::get<1>(alibis[i]) -
					std::get<1>(grazings[l + 1])) >
			     square(std::get<2>(alibis[i]) -
				    std::get<2>(grazings[l + 1])))
			++count;
	}

	std::cout << count << std::endl;

	return 0;
}
