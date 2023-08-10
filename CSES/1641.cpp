#include <algorithm>
#include <iostream>
#include <vector>

int N, X;
std::vector<std::pair<int, int>> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> X;

	for (int i = 0; i < N; ++i) {
		int value;
		std::cin >> value;

		A.push_back({value, i + 1});
	}

	if (N < 3)
		goto impossible;

	std::sort(A.begin(), A.end());

	for (int i = 0; i < N; ++i) {
		int target = X - A[i].first;

		int left = 0, right = N - 1;
		while (left < right) {
			if (left == i)
				++left;
			else if (right == i)
				--right;

			int diff = A[left].first + A[right].first - target;

			if (diff > 0)
				--right;
			else if (diff < 0)
				++left;
			else {
				std::cout << A[left].second << " "
					  << A[right].second << " "
					  << A[i].second << std::endl;
				return 0;
			}
		}
	}

impossible:;
	std::cout << "IMPOSSIBLE" << std::endl;

	return 0;
}
