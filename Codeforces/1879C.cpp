#include <iostream>

#define MOD 998244353

std::string S;

long long factorial(long long x) {
	long long res = 1;
	for (long long i = 2; i <= x; ++i)
		res *= i, res %= MOD;

	return res;
}

void solve() {
	std::cin >> S;

	int ops = 0;
	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == S[i + 1])
			++ops;
	}

	int i = 0;
	long long seq = 1;
	while (i < S.length() - 1) {
		int count = 1;
		while (S[i] == S[i + 1])
			++count, ++i;

		seq *= count, seq %= MOD;
		++i;
	}

	seq *= factorial(ops), seq %= MOD;

	std::cout << ops << " " << seq << std::endl;
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
