#include <iostream>
#include <vector>

int N;

void solve() {
	std::cin >> N;

	long long row_sum = 0, row_min = 1e9, col_sum = 0, col_min = 1e9;

	for (int i = 0; i < N; ++i) {
		long long A;
		std::cin >> A;

		row_sum += A;
		row_min = std::min(row_min, A);
	}
	for (int i = 0; i < N; ++i) {
		long long B;
		std::cin >> B;

		col_sum += B;
		col_min = std::min(col_min, B);
	}

	std::cout << std::min(row_sum + col_min * N, col_sum + row_min * N)
		  << std::endl;
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
