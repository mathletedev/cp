#include <iostream>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	if (N == 1) {
		std::cout << 0 << std::endl;
		return;
	}

	int max_index = 0, min_index = 0;
	for (int i = 0; i < N; ++i) {
		if (A[i] > A[max_index])
			max_index = i;
		if (A[i] < A[min_index])
			min_index = i;
	}
	int max = A[max_index], min = A[min_index];

	if (max == 0 && min == 0) {
		std::cout << 0 << std::endl;
		return;
	}

	if (max > 0) {
		int ops_max = 0;
		while (max <= 20) {
			max *= 2;
			++ops_max;
		}

		std::cout << ops_max + (N - 1) * 2 << std::endl;
		for (int i = 0; i < ops_max; ++i)
			std::cout << max_index + 1 << " " << max_index + 1
				  << std::endl;

		std::cout << "2 " << max_index + 1 << std::endl;
		std::cout << "2 " << max_index + 1 << std::endl;

		for (int i = 2; i < N; ++i) {
			std::cout << i + 1 << " " << i << std::endl;
			std::cout << i + 1 << " " << i << std::endl;
		}
	} else {
		int ops_min = 0;
		while (min >= -20) {
			min *= 2;
			++ops_min;
		}

		std::cout << ops_min + (N - 1) * 2 << std::endl;
		for (int i = 0; i < ops_min; ++i)
			std::cout << min_index + 1 << " " << min_index + 1
				  << std::endl;

		std::cout << N - 1 << " " << min_index + 1 << std::endl;
		std::cout << N - 1 << " " << min_index + 1 << std::endl;

		for (int i = N - 2; i >= 1; --i) {
			std::cout << i << " " << i + 1 << std::endl;
			std::cout << i << " " << i + 1 << std::endl;
		}
	}
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
