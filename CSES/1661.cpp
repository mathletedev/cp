#include <iostream>
#include <map>

int N, X;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> X;

	std::map<long long, int> sums;
	sums[0] = 1;

	long long ans = 0, prefix = 0;
	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;

		prefix += x;

		ans += sums[prefix - X];
		++sums[prefix];
	}

	std::cout << ans << std::endl;

	return 0;
}
