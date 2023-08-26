#include <iostream>
#include <vector>

int N;
std::vector<int> A, horizontal;

void solve() {
	std::cin >> N;
	A.assign(N, 0);
	horizontal.clear();

	for (int &x : A)
		std::cin >> x;

	if (A[0] != N) {
		std::cout << "NO" << std::endl;
		return;
	}

	for (int i = N - 1; i >= 0; --i) {
		while (horizontal.size() < A[i])
			horizontal.push_back(i + 1);
	}

	for (int i = 0; i < N; ++i) {
		if (A[i] != horizontal[i]) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;
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
