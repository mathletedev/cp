#include <iostream>
#include <vector>

#define MOD 998244353
#define MAX_N 25
#define MAX_LEN 100
#define CHARS 26

using ll = long long;

ll solve() {
	int N;
	std::cin >> N;

	std::vector<std::string> S(N);
	int max_len = 0;
	for (auto &Si : S) {
		std::cin >> Si;
		max_len = std::max(max_len, (int)Si.size());
	}

	ll dp[MAX_LEN][CHARS][MAX_N] = {};

	for (int i = 0; i < MAX_LEN; ++i) {
		for (int j = 0; j < N; ++j) {
			if (S[j].size() <= i) {
				continue;
			}

			char c = S[j][i];

			if (i == 0) {
				if (c == '?') {
					// fill entire row
					for (int k = 0; k < CHARS; ++k) {
						for (int l = 0; l < N; ++l) {
							dp[0][k][l] = 1;
						}
					}
				} else {
					for (int k = 0; k < N; ++k) {
						dp[0][c - 'A'][k] = 1;
					}
				}
				continue;
			}

			char prev_c = S[j][i - 1];
			ll next = dp[i - 1][prev_c - 'A'][j];

			if (prev_c == '?') {
				next = (next * CHARS) % MOD;
			}

			next %= MOD;

			if (c == '?') {
				for (int k = 0; k < CHARS; ++k) {
					dp[i][k][j] =
					    std::max(dp[i][k][j], next);
				}
			} else {
				dp[i][c - 'A'][j] =
				    std::max(dp[i][c - 'A'][j], next);
			}
		}
	}

	ll res = 0;
	for (int i = 0; i < max_len; ++i) {
		for (int j = 0; j < CHARS; ++j) {
			ll max = 0;

			for (int k = 0; k < N; ++k) {
				max = std::max(max, dp[i][j][k]);
			}

			res += max;
		}
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
