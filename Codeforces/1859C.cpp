#include <iostream>
#include <stack>
#include <vector>

int N;

void solve() {
	std::cin >> N;

	std::vector<int> sieve(N * N + 1, 1);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j)
			sieve[i * j] = 0;
	}

	int ans = 0;

	for (int max = N * N; max >= 1; --max) {
		if (sieve[max])
			continue;

		std::vector<std::vector<int>> pairs(N + 1, std::vector<int>());
		bool impossible = 0;
		for (int i = N; i >= 1; --i) {
			int curr = std::min(max / i, N);
			if (curr < 1) {
				impossible = 1;
				break;
			}

			pairs[curr].push_back(i);
		}
		if (impossible)
			break;

		std::stack<int> remaining;
		int tmp_ans = -max;

		for (int i = 1; i <= N; ++i) {
			remaining.push(i);

			for (int x : pairs[i]) {
				if (remaining.empty())
					goto end;

				tmp_ans += remaining.top() * x;
				remaining.pop();
			}
		}

	end:;
		ans = std::max(ans, tmp_ans);
	}

	std::cout << ans << std::endl;
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
