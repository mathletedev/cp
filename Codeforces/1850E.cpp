#include <iostream>
#include <vector>

long long N, C;
std::vector<int> S;

long long square(long long x) { return x * x; }

bool is_possible(long long W) {
	long long sum = 0;
	for (int x : S) {
		sum += square(x + W * 2);

		if (sum >= C)
			return 1;
	}

	return 0;
}

void solve() {
	std::cin >> N >> C;
	S.assign(N, 0);

	for (int &x : S)
		std::cin >> x;

	long long low = 0, high = 1e9;
	while (low < high) {
		long long mid = (low + high) / 2;

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
