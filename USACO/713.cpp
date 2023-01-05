#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("cowqueue.in", "r", stdin);
	freopen("cowqueue.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<std::pair<int, int>> queue(n);
	for (int i = 0; i < n; ++i) {
		int a, b;
		std::cin >> a >> b;
		queue[i] = {a, b};
	}

	std::sort(queue.begin(), queue.end());

	int time = 0;
	for (std::pair<int, int> cow : queue) {
		time = std::max(time, cow.first);
		time += cow.second;
	}

	std::cout << time << std::endl;

	return 0;
}
