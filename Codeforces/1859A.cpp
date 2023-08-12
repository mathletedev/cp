#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());

	std::vector<int> lb, lc;

	int low = 0, high = N - 1;
	while (low < N && A[low] == A[0])
		lb.push_back(A[low++]);

	if (low == N) {
		std::cout << -1 << std::endl;
		return;
	}

	while (high >= 0 && A[high] == A[N - 1])
		lc.push_back(A[high--]);

	for (int i = low; i < high + 1; ++i)
		(A[i] % 2 == 1 ? lb : lc).push_back(A[i]);

	std::cout << lb.size() << " " << lc.size() << std::endl;
	for (int x : lb)
		std::cout << x << " ";
	std::cout << std::endl;
	for (int x : lc)
		std::cout << x << " ";
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
