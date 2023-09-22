#include <algorithm>
#include <iostream>
#include <vector>

int N, K;
std::vector<std::pair<int, int>> A;

void solve() {
	std::cin >> N >> K;
	A.clear();

	for (int i = 1; i <= N; ++i) {
		int x;
		std::cin >> x;

		if (x % K == 0)
			std::cout << i << " ";
		else
			A.push_back({x % K, N - i});
	}

	std::sort(A.begin(), A.end());

	for (int i = A.size() - 1; i >= 0; --i)
		std::cout << N - A[i].second << " ";
	std::cout << std::endl;
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
