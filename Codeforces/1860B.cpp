#include <iostream>

long long M, K, A_1, A_K;

void solve() {
	std::cin >> M >> K >> A_1 >> A_K;

	long long cost = std::max(M - A_K * K, M % K);
	long long ones = std::min(A_1, cost - cost / K * K);
	cost -= ones;
	cost = std::max<long long>(0, cost - (A_1 - ones) / K * K);

	std::cout << cost / K + cost - cost / K * K << std::endl;
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
