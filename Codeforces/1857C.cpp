#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	int size = N * (N - 1) / 2;
	A.assign(size, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());

	int jump = 0;
	for (int i = 1; i < N; ++i) {
		std::cout << A[jump] << " ";
		jump += N - i;
	}

	std::cout << A[size - 1] << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
