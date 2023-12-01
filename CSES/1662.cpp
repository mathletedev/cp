#include <iostream>
#include <vector>

long long mod(int a, int b) { return (a % b + b) % b; }

int N;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	std::vector<long long> sums(N, 0);
	sums[0] = 1;

	long long ans = 0, prefix = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;

		prefix += x;
		prefix %= N;

		ans += sums[mod(prefix - N, N)];
		++sums[mod(prefix, N)];
	}

	std::cout << ans << std::endl;

	return 0;
}
