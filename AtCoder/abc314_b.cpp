#include <iostream>
#include <vector>

int N, X;
std::vector<std::vector<int>> bets(37);
std::vector<int> num_bets;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	num_bets.assign(N, 0);

	for (int i = 0; i < N; ++i) {
		int C;
		std::cin >> C;
		num_bets[i] = C;

		for (int j = 0; j < C; ++j) {
			int A;
			std::cin >> A;

			bets[A].push_back(i);
		}
	}

	std::cin >> X;

	std::vector<int> winners = bets[X];

	if (winners.size() == 0) {
		std::cout << 0 << std::endl;
		return 0;
	}

	int fewest = 1e9;
	for (int x : winners)
		fewest = std::min(fewest, num_bets[x]);

	std::vector<int> ans;
	for (int x : winners) {
		if (num_bets[x] == fewest)
			ans.push_back(x);
	}

	std::cout << ans.size() << std::endl;
	for (int x : ans)
		std::cout << x + 1 << " ";
	std::cout << std::endl;

	return 0;
}
