#include <algorithm>
#include <iostream>
#include <vector>

int N, T;
std::string infected;
std::vector<std::pair<int, std::pair<int, int>>> interactions;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("tracing.in", "r", stdin);
	freopen("tracing.out", "w", stdout);

	std::cin >> N >> T >> infected;

	std::vector<int> num_interactions(N, 0);
	for (int i = 0; i < T; ++i) {
		int t, x, y;
		std::cin >> t >> x >> y, --x, --y;

		interactions.push_back({t, {x, y}});

		++num_interactions[x];
		++num_interactions[y];
	}

	std::sort(interactions.begin(), interactions.end());

	int x = 0, min_K = 1e9, max_K = 0;
	for (int i = 0; i < N; ++i) {
		if (infected[i] == '0')
			continue;

		bool possible = 0;

		for (int K = 0; K <= T; ++K) {
			std::string curr = std::string(N, '0');
			curr[i] = '1';
			std::vector<int> num_shakes(N, 0);

			for (int j = 0; j < T; ++j) {
				auto cows = interactions[j].second;

				if (curr[cows.first] == '1')
					++num_shakes[cows.first];
				if (curr[cows.second] == '1')
					++num_shakes[cows.second];
				if (curr[cows.first] == '1' &&
				    num_shakes[cows.first] <= K)
					curr[cows.second] = '1';
				if (curr[cows.second] == '1' &&
				    num_shakes[cows.second] <= K)
					curr[cows.first] = '1';
			}

			if (curr == infected) {
				possible = 1;
				min_K = std::min(min_K, K);
				max_K = std::max(max_K, K);
			}
		}

		if (possible)
			++x;
	}

	std::cout << x << " " << min_K << " ";
	if (max_K == T)
		std::cout << "Infinity";
	else
		std::cout << max_K;
	std::cout << std::endl;

	return 0;
}
