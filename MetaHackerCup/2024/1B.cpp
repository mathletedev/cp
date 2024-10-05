#include <iostream>

#define MAX_N 10000000

int N;

bool sieve[MAX_N + 1] = {};

int solve() {
	std::cin >> N;

	if (N < 5) {
		return 0;
	}

	int count = 1;

	for (int i = 5; i <= N; ++i) {
		count += !sieve[i] && !sieve[i - 2];
	}

	return count;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	for (int i = 2; i * i <= MAX_N; ++i) {
		if (!sieve[i]) {
			for (int j = i * i; j <= MAX_N; j += i) {
				sieve[j] = true;
			}
		}
	}

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": " << solve() << std::endl;
	}

	return 0;
}
