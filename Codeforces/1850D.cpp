#include <algorithm>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;

void solve() {
	std::cin >> N >> K;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());

	int count = 1, max_count = 1;
	for (int i = 1; i < N; ++i) {
		if (A[i] - A[i - 1] <= K) {
			max_count = std::max(max_count, ++count);
			continue;
		}

		count = 1;
	}

	std::cout << N - max_count << std::endl;
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
