#include <iostream>
#include <vector>

int P;

void solve() {
	std::cin >> P;

	std::vector<int> ans;

	for (int i = 2; i * i <= P; ++i) {
		while (P % i == 0) {
			ans.push_back(i);
			P /= i;
		}
	}
	if (P >= 2)
		ans.push_back(P);

	int sum = 0;
	for (int x : ans)
		sum += x;

	if (sum > 41) {
		std::cout << -1 << std::endl;
		return;
	}

	std::cout << ans.size() + 41 - sum << " ";
	for (int x : ans)
		std::cout << x << " ";
	for (int i = 0; i < 41 - sum; ++i)
		std::cout << 1 << " ";
	std::cout << std::endl;
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
