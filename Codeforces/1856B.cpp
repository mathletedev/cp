#include <iostream>
#include <vector>

long long N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	if (N == 1) {
		std::cout << "NO" << std::endl;
		return;
	}

	long long sum_A = 0, sum_B = 0;
	for (int i = 0; i < N; ++i) {
		sum_B += A[i] == 1 ? 2 : 1;
		sum_A += A[i];
	}

	std::cout << (sum_B <= sum_A ? "YES" : "NO") << std::endl;
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
