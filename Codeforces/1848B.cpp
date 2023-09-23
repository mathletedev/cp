#include <iostream>
#include <vector>

int N, K;
std::vector<int> C;

void solve() {
	std::cin >> N >> K;
	C.assign(N, 0);

	for (int &x : C)
		std::cin >> x;

	std::vector<int> last(K + 1, 0), max(K + 1, 0), max2(K + 1, 0);

	for (int i = 1; i <= N; ++i) {
		int colour = C[i - 1];
		int dist = i - last[colour] - 1;

		if (dist >= max[colour]) {
			max2[colour] = max[colour];
			max[colour] = dist;
		} else if (dist >= max2[colour])
			max2[colour] = dist;

		last[colour] = i;
	}

	int ans = 1e9;
	for (int i = 1; i <= K; ++i) {
		int dist = N - last[i];

		if (dist >= max[i]) {
			max2[i] = max[i];
			max[i] = dist;
		} else if (dist >= max2[i])
			max2[i] = dist;

		ans = std::min(ans, std::max(max[i] / 2, max2[i]));
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
