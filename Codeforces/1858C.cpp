#include <iostream>
#include <vector>

int N;

void solve() {
	std::cin >> N;

	std::vector<int> ans(N);
	ans[0] = 1;

	int curr = 1;
	for (int i = 1; i < N; ++i) {
		if (ans[i - 1] * 2 > N)
			ans[i] = curr += 2;
		else
			ans[i] = ans[i - 1] * 2;
	}

	for (int x : ans)
		std::cout << x << " ";
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
