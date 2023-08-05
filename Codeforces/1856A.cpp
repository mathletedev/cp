#include <iostream>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	int ans = 0;
	for (int i = N - 2; i >= 0; --i)
		if (A[i] > A[i + 1])
			ans = std::max(ans, A[i]);

	std::cout << ans << std::endl;
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
