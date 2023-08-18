#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A;

bool is_possible(int dist) {
	int prev = A[0], count = 1;
	for (int x : A) {
		if (x - prev > 2 * dist)
			prev = x, ++count;
	}

	return count <= 3;
}

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());

	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high) / 2;

		if (is_possible(mid))
			high = mid;
		else
			low = mid + 1;
	}

	std::cout << low << std::endl;
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
