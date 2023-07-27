#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int N, M;
std::vector<std::pair<long long, long long>> fields;

bool is_possible(long long d) {
	long long pos = fields[0].first;
	int field = 0;

	for (int i = 1; i < N; ++i) {
		pos += d;

		while (fields[field].second < pos) {
			++field;
			if (field >= M)
				return 0;
		}

		pos = std::max(pos, fields[field].first);
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);

	std::cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		long long A, B;
		std::cin >> A >> B;

		fields.push_back({A, B});
	}

	std::sort(fields.begin(), fields.end());

	long long low = 0, high = 1e18;
	while (low < high) {
		long long mid = (low + high) / 2 + (low + high) % 2;

		if (is_possible(mid))
			low = mid;
		else
			high = mid - 1;
	}

	std::cout << low << std::endl;

	return 0;
}
