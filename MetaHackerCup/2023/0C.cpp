#include <algorithm>
#include <iostream>
#include <vector>

#define INF INT32_MAX

int N, size;
std::vector<int> A;

int find_missing(long long target) {
	int res = target / 2, skipped = 0;
	int left = 0, right = size - 1;
	while (left <= right) {
		long long sum = A[left] + A[right];

		if (sum == target) {
			++left, --right;
			continue;
		}

		++skipped;

		if (sum < target)
			res = target - A[left++];
		else
			res = target - A[right--];
	}

	return skipped <= 1 && res > 0 ? res : INF;
}

void solve() {
	std::cin >> N;
	size = 2 * N - 1;
	A.assign(size, 0);

	for (int &x : A)
		std::cin >> x;

	if (N == 1) {
		std::cout << 1 << std::endl;
		return;
	}

	std::sort(A.begin(), A.end());

	int ans = std::min({
	    find_missing(A[0] + A[size - 1]),
	    find_missing(A[1] + A[size - 1]),
	    find_missing(A[0] + A[size - 2]),
	});

	std::cout << (ans == INF ? -1 : ans) << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
