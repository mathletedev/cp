#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;

bool is_possible(int x) {
	if (A[N - 1] >= x)
		return 1;

	for (int i = 0; i < N - 1; ++i) {
		if (A[i] >= x)
			return 1;

		int operations = 0;
		for (int j = i; j < N; ++j) {
			int target = x - (j - i);

			if (j == N - 1) {
				if (A[j] >= target)
					return 1;
				break;
			}

			operations += target - A[j];

			if (operations > K)
				break;
			if (A[j] >= target)
				return 1;
		}
	}

	return 0;
}

void solve() {
	std::cin >> N >> K;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	int low = 0, high = 1e9;
	while (low < high) {
		int mid = (low + high) / 2 + (low + high) % 2;

		if (is_possible(mid))
			low = mid;
		else
			high = mid - 1;
	}

	std::cout << low << std::endl;
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
