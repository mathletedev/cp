#include <iostream>
#include <vector>

int N, M;
std::string S;
std::vector<long long> A;

void solve() {
	std::cin >> N >> M >> S;
	A.assign(N, 0);

	for (long long &x : A)
		std::cin >> x;
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
