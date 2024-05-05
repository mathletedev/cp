#include <algorithm>
#include <iostream>
#include <vector>

struct Point {
		long long x, y;
		bool right, top;
};

long long N, X;
std::vector<Point> vertices;
std::vector<long long> slopes;

bool cmp(const long long &a, const long long &b) {
	return std::abs(a) > std::abs(b);
}

void solve() {
	vertices.clear();
	slopes.clear();

	std::cin >> N >> X;
	slopes.assign(4 * N, 0);

	for (int i = 0; i < N; ++i) {
		int y1, y2, x2;
		std::cin >> y1 >> y2 >> x2;

		vertices.push_back({X, y1, 0, 0});
		vertices.push_back({X, y2, 0, 1});
		vertices.push_back({x2, y1, 1, 0});
		vertices.push_back({x2, y2, 1, 1});
	}

	int num_pos = 0, num_neg = 0;
	for (long long &x : slopes) {
		std::cin >> x;

		if (x > 0)
			++num_pos;
		else if (x < 0)
			++num_neg;
	}

	if (std::min(num_pos, num_neg) < N) {
		std::cout << -1 << std::endl;
		return;
	}

	std::sort(slopes.begin(), slopes.end(), cmp);

	std::vector<bool> used(4 * N);
	long long low = INT64_MAX, high = INT64_MIN;
	for (int i = 0; i < 4 * N; ++i) {
		bool pos = slopes[i] > 0;
		long long min = pos ? INT64_MIN : INT64_MAX;
		int min_index = -1;

		for (int j = 0; j < 4 * N; ++j) {
			if (used[j]) continue;

			if (vertices[j].right && ((pos && vertices[j].top) ||
						  (!pos && !vertices[j].top)))
				continue;

			long long y = vertices[j].y - vertices[j].x * slopes[i];
			if ((pos && y > min) || (!pos && y < min)) {
				min = y;
				min_index = j;
			}
		}

		low = std::min(low, min);
		high = std::max(high, min);

		used[min_index] = 1;
	}

	std::cout << high - low << std::endl;
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
