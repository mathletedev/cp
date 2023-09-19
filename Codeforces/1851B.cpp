#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> A;

void solve() {
	std::cin >> N;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::vector<int> evens, odds;
	for (int x : A)
		(x % 2 == 0 ? evens : odds).push_back(x);

	std::sort(evens.begin(), evens.end());
	std::sort(odds.begin(), odds.end());

	int evens_index = 0, odds_index = 0;
	std::vector<int> merged;
	for (int x : A) {
		if (x % 2 == 0)
			merged.push_back(evens[evens_index++]);
		else
			merged.push_back(odds[odds_index++]);
	}

	for (int i = 0; i < N - 1; ++i) {
		if (merged[i] > merged[i + 1]) {
			std::cout << "NO" << std::endl;
			return;
		}
	}
	std::cout << "YES" << std::endl;
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
