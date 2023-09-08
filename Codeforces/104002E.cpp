#include <iostream>
#include <set>
#include <vector>

int N;
std::vector<int> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	if (N == 1) {
		std::cout << A[0] << std::endl;
		return 0;
	}

	std::multiset<int> taken;
	taken.insert(std::max(A[0], A[1]));

	for (int i = 1; i < N / 2; ++i) {
		taken.insert(std::max(A[i * 2], A[i * 2 + 1]));

		int min = std::min(A[i * 2], A[i * 2 + 1]);
		if (min > *taken.begin()) {
			taken.erase(taken.begin());
			taken.insert(min);
		}
	}

	long long ans = 0;
	for (int x : taken)
		ans += x;

	std::cout << ans << std::endl;

	return 0;
}
