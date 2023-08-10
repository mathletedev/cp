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

	std::sort(A.begin(), A.end());

	int left = 0, right = N - 1;
	while (left < right) {
		int diff = A[left].first + A[right].first - X;

		if (diff > 0)
			--right;
		else if (diff < 0)
			++left;
		else {
			std::cout << A[left].second << " " << A[right].second
				  << std::endl;
			return 0;
		}
	}

	std::cout << "IMPOSSIBLE" << std::endl;

	return 0;
}
