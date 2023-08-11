#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<std::pair<int, int>> movies;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int A, B;
		std::cin >> A >> B;

		movies.push_back({B, A});
	}

	std::sort(movies.begin(), movies.end());

	int time = movies[0].first, ans = 1;
	for (int i = 1; i < N; ++i) {
		if (movies[i].second >= time)
			time = movies[i].first, ++ans;
	}

	std::cout << ans << std::endl;

	return 0;
}
