#include <algorithm>
#include <iostream>

int N, K;
std::string S;

void solve() {
	std::cin >> N >> K >> S;

	if (K % 2 == 0) {
		std::sort(S.begin(), S.end());
		std::cout << S << std::endl;
		return;
	}

	std::string a, b;
	for (int i = 0; i < N; i += 2)
		a += S[i];
	for (int i = 1; i < N; i += 2)
		b += S[i];

	std::sort(a.begin(), a.end());
	std::sort(b.begin(), b.end());

	for (int i = 0; i < a.length(); ++i) {
		std::cout << a[i] << "";
		if (i < b.length())
			std::cout << b[i] << "";
	}
	std::cout << std::endl;
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
