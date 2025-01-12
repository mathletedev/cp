#include <iostream>
#include <string>

using ll = long long;

int solve() {
	ll A, B, M;
	std::string A_str, B_str;

	std::cin >> A >> B >> M;

	A_str = std::to_string(A);
	B_str = std::to_string(B);

	ll ans = 0;

	// number of digits
	for (int n = 1; n <= B_str.size(); n += 2) {
		if (n < A_str.size()) {
			continue;
		}

		int half = (n + 1) / 2;

		ll add = 1;
		for (int i = 1; i < n; ++i) {
			add *= 10;
			++add;
		}

		ll curr = 1;
		for (int i = 2; i <= half; ++i) {
			curr *= 10;
			curr += i;
		}
		for (int i = half - 1; i > 0; --i) {
			curr *= 10;
			curr += i;
		}

		for (int i = 0; i < 10 - half; ++i) {
			if (curr < A || curr > B) {
				continue;
			}

			if (curr % M == 0) {
				++ans;
			}

			curr += add;
		}
	}

	return ans;
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
