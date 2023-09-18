#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;
std::vector<bool> exists;

void solve() {
	std::cin >> N >> K;
	A.assign(N, 0);
	exists.assign(N + 1, 0);

	for (int &x : A)
		std::cin >> x, exists[x] = 1;

	for (int i = 1; i <= K; ++i) {
		if (!exists[i]) {
			std::cout << "0 ";
			continue;
		}

		long long low = 0, high = 0;
		for (int j = 0; j < N; ++j) {
			if (A[j] >= i) {
				low = j;
				break;
			}
		}
		for (int j = N - 1; j >= 0; --j) {
			if (A[j] >= i) {
				high = j;
				break;
			}
		}

		std::cout << (high - low + 1) * 2 << " ";
	}

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
