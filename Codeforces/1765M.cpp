#include <iostream>

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) {
				std::cout << n / i << " " << n - n / i
					  << std::endl;
				goto skip;
			}
		}

		std::cout << "1 " << n - 1 << std::endl;

	skip:;
	}

	return 0;
}
