#include <iostream>

#define MOD 998244353

using ll = long long;

ll G, W, L;

ll solve() {
	std::cin >> G >> W >> L;

	ll d = G - W;			  // difference
	ll m = ((L * 2) % MOD + 1) % MOD; // multiplier
	ll res = 0;

	while (d > 0) {
		if (d % 2 == 1) {
			res = (res + m) % MOD;
		}

		m = (m * 2) % MOD;
		d /= 2;
	}

	return res;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": " << solve() << std::endl;
	}

	return 0;
}
