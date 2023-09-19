#include <iostream>
#include <set>
#include <vector>

long long N;
std::vector<long long> A;

void solve() {
	std::cin >> N;
	A.assign(N - 1, 0);

	for (long long &x : A)
		std::cin >> x;

	if (A[N - 2] != N * (N + 1) / 2) {
		A.push_back(N * (N + 1) / 2);

		std::set<long long> found;
		long long prev = 0;
		for (long long x : A) {
			found.insert(x - prev);
			prev = x;
		}

		for (int i = 1; i <= N; ++i) {
			if (found.find(i) == found.end()) {
				std::cout << "NO" << std::endl;
				return;
			}
		}
		std::cout << "YES" << std::endl;
		return;
	}

	std::set<long long> found;
	long long prev = 0;
	for (long long x : A) {
		found.insert(x - prev);
		prev = x;
	}

	long long num_unfound = 0, sum_unfound = 0;
	for (int i = 1; i <= N; ++i) {
		if (found.find(i) != found.end())
			continue;

		++num_unfound;
		sum_unfound += i;
	}

	std::cout << (num_unfound > 2 ||
			      (found.find(sum_unfound) == found.end())
			  ? "NO"
			  : "YES")
		  << std::endl;
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
