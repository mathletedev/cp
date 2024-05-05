#include <iostream>
#include <vector>

#define MAX_A 4e9

int N;
std::vector<long long> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	A.assign(N, 0);

	long long min = MAX_A;
	for (long long &x : A)
		std::cin >> x, min = std::min(min, x);

	long long max_l = min / 4;

	long long ans = 0;
	for (long long l = 1; l <= max_l; ++l) {
		std::vector<bool> seen(l);
		for (long long x : A)
			seen[x % l] = 1;

		int count = 0;
		for (bool x : seen)
			count += x;

		if (count <= 3)
			ans += l;
	}

	std::cout << ans << std::endl;

	return 0;
}
