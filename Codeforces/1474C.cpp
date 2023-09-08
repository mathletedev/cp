#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N * 2, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());

	for (int i = 0; i < N * 2 - 1; ++i) {
		int x = A[N * 2 - 1] + A[i];

		std::vector<std::pair<int, int>> chosen;
		chosen.push_back({A[N * 2 - 1], A[i]});

		std::multiset<int> remaining;
		for (int x : A)
			remaining.insert(x);

		while (!remaining.empty()) {
			int rem =
		}

		if (1) {
			std::cout << "YES" << std::endl;
		}
	}

	std::cout << "NO" << std::endl;
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
