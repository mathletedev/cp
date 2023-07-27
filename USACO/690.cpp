#include <iostream>
#include <queue>
#include <vector>

int N, T;
std::vector<int> cows;

bool is_valid(int k) {
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	int time = 0;

	for (int i = 0; i < N; ++i) {
		if (pq.size() == k) {
			time = pq.top();
			pq.pop();
		}
		if (time + cows[i] > T)
			return 0;
		pq.push(time + cows[i]);
	}

	return 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

	std::cin >> N >> T;
	cows.assign(N, 0);

	for (int &x : cows)
		std::cin >> x;

	int low = 1, high = N;
	while (low < high) {
		int mid = (low + high) / 2;

		if (is_valid(mid))
			high = mid;
		else
			low = mid + 1;
	}

	std::cout << high << std::endl;

	return 0;
}
