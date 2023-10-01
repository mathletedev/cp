#include <algorithm>
#include <iostream>
#include <vector>

int N, M, K;
std::vector<int> A, B;

void solve() {
	std::cin >> N >> M >> K;
	A.resize(N), B.resize(M);

	long long sum_A = 0;
	for (int &x : A)
		std::cin >> x, sum_A += x;
	for (int &x : B)
		std::cin >> x;

	std::sort(A.begin(), A.end());
	std::sort(B.begin(), B.end());

	long long ans = sum_A;
	ans -= A[0];
	ans += std::max(A[0], B[M - 1]);

	if (K % 2 == 0) {
		ans -= std::max(A[N - 1], B[M - 1]);
		ans += std::min(A[0], B[0]);
	}

	std::cout << ans << std::endl;
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
