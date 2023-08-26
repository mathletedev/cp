#include <iostream>
#include <set>
#include <vector>

int N, M, D;
std::vector<int> A;

void solve() {
	std::cin >> N >> M >> D;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	long long ans = 0, curr = 0;
	std::set<std::pair<int, int>> chosen;
	for (int i = 0; i < N; ++i) {
		ans = std::max(ans, curr + A[i] - (long long)D * (i + 1));

		if (A[i] > 0) {
			chosen.insert({A[i], i});
			curr += A[i];

			if (chosen.size() >= M) {
				curr -= chosen.begin()->first;
				chosen.erase(chosen.begin());
			}
		}
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
