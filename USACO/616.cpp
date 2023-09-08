#include <cstdio>
#include <iostream>
#include <vector>

int N;
std::vector<int> R;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);

	std::cin >> N;
	R.assign(N, 0);

	for (int &x : R)
		std::cin >> x;

	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		int total = 0, dist = 1;

		int j = i + 1;
		while (j != i) {
			if (j == N) {
				j = 0;
				continue;
			}

			total += R[j++] * dist++;
		}

		ans = std::min(ans, total);
	}

	std::cout << ans << std::endl;

	return 0;
}
