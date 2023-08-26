#include <iostream>
#include <vector>

int X, Y, N;

void solve() {
	std::cin >> X >> Y >> N;

	std::vector<int> ans;
	ans.push_back(X);

	for (int i = 1; i < N; ++i)
		ans.push_back(ans[i - 1] + N - i);

	if (ans[N - 1] > Y) {
		std::cout << -1 << std::endl;
		return;
	}

	int extra = Y - ans[N - 1];
	for (int i = 1; i < N; ++i)
		ans[i] += extra;

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
