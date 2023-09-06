#include <iostream>
#include <set>
#include <vector>

int N, B;
std::vector<int> F;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("snowboots.in", "r", stdin);
	freopen("snowboots.out", "w", stdout);

	std::cin >> N >> B;
	F.assign(N, 0);

	for (int &x : F)
		std::cin >> x;

	for (int i = 0; i < B; ++i) {
		int S, D;
		std::cin >> S >> D;

		std::set<int> tiles;
		for (int i = 0; i < N; ++i) {
			if (F[i] <= S)
				tiles.insert(i);
		}

		bool ans = 1;
		int curr = 0;
		while (curr < N - 1) {
			auto itr = tiles.upper_bound(curr + D);
			--itr;
			if (curr == *itr) {
				ans = 0;
				break;
			}

			curr = *itr;
		}

		std::cout << ans << std::endl;
	}

	return 0;
}
