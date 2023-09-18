#include <iostream>
#include <set>
#include <vector>

int N;
std::vector<int> A, B;

void solve() {
	std::cin >> N;
	A.assign(N, 0), B.assign(N, 0);

	for (int &x : A)
		std::cin >> x;
	for (int &x : B)
		std::cin >> x;

	std::vector<int> diff(N);
	int max = -2e9;
	for (int i = 0; i < N; ++i) {
		diff[i] = A[i] - B[i];
		max = std::max(max, diff[i]);
	}

	std::set<int> ans;
	for (int i = 0; i < N; ++i)
		if (diff[i] == max)
			ans.insert(i + 1);

	std::cout << ans.size() << std::endl;
	for (auto it = ans.begin(); it != ans.end(); ++it)
		std::cout << *it << " ";
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
