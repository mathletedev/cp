#include <iostream>
#include <map>
#include <vector>

int N, M, K;
std::map<int, int> cows;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M >> K;

	for (int i = 0; i < N; ++i) {
		int W, A;
		std::cin >> W >> A;

		cows[W] = A;
	}

	int ans = 0;
	int i = 0;
	while (1) {
		std::map<int, int>::iterator curr = cows.begin();

		int min = 1e9;
		int w = -K;
		int height = 0;
		std::vector<int> used;
		while (1) {
			curr = cows.lower_bound(w + K);
			if (curr == cows.end())
				break;

			min = std::min(min, curr->second);

			w = curr->first;
			++height;

			used.push_back(curr->first);
		}

		if (min == 1e9)
			min = 0;
		min = std::min(min, M - i);

		ans += min * height;

		i += min;
		if (i == M)
			break;

		for (int x : used) {
			auto cow = cows.find(x);
			cow->second -= min;
			if (!cow->second)
				cows.erase(cow);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
