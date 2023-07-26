#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> diamonds;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	std::cin >> N >> K;
	diamonds.assign(N, 0);

	for (int &x : diamonds)
		std::cin >> x;

	std::sort(diamonds.begin(), diamonds.end());

	int right = 0;
	std::vector<int> max_first(N);

	for (int left = 0; left < N; ++left) {
		while (right < N && diamonds[right] - diamonds[left] <= K)
			++right;

		max_first[left] = right - left;
	}

	std::vector<int> max_second(N);
	int max_next = 0;

	for (int i = N - 1; i >= 0; --i) {
		max_second[i] = max_next;

		max_next = std::max(max_next, max_first[i]);
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		int num = max_first[i] + max_second[i + max_first[i] - 1];

		ans = std::max(ans, num);
	}

	std::cout << ans << std::endl;

	return 0;
}
