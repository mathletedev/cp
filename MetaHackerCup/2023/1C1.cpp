#include <iostream>
#include <vector>

int N, Q;
std::string S;

void solve() {
	std::cin >> N >> S >> Q;

	std::vector<int> count(N);

	for (int i = 0; i < Q; ++i) {
		int B;
		std::cin >> B;

		++count[B - 1];
	}

	for (int i = 0; i < N; ++i) {
		if (count[i] % 2 == 1) {
			for (int j = i; j < N; j += i + 1)
				S[j] = (S[j] == '0' ? '1' : '0');
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] == '1') {
			++ans;

			for (int j = i; j < N; j += i + 1)
				S[j] = (S[j] == '0' ? '1' : '0');
		}
	}

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
