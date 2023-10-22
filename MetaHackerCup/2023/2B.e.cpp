#include <iostream>
#include <vector>

int N;
std::vector<int> A, B;

void solve() {
	std::cin >> N;
	A.assign(N, 0);
	B.assign(N, 0);

	std::vector<int> AB;

	for (int &x : A)
		std::cin >> x, AB.push_back(x);
	for (int &x : B)
		std::cin >> x, AB.push_back(x);

	int left = 0, right = 2 * N - 1;
	while (left < right - 1) {
		if (AB[left] == AB[right]) {
			++left, --right;
			continue;
		}

		while (AB[left] != AB[right])
			++left;
	}

	if (left == right || AB[left] != AB[right]) {
		std::cout << -1 << std::endl;
		return;
	}

	std::vector<int> new_A, new_B;
	for (int i = 0; i < N; ++i) {
		new_A.push_back(AB[right - N + i]);
		new_B.push_back(AB[(right + i) % (N * 2)]);
		if (AB[left - i] != AB[(right + i) % (N * 2)]) {
			std::cout << -1 << std::endl;
			return;
		}
	}

	bool all_less = 1, all_greater = 1;
	for (int i = 0; i < N / 2; ++i) {
		if (new_A[i] >= new_B[i])
			all_less = 0;
		if (new_A[i] <= new_B[i])
			all_greater = 0;
	}

	if (all_less)
		right -= N;
	std::cout << right << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
