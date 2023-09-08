#include <iostream>
#include <map>
#include <vector>

int N;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("mowing.in", "r", stdin);
	freopen("mowing.out", "w", stdout);

	std::cin >> N;

	int time = 0, ans = 1e9;
	std::pair<int, int> pos = {0, 0};
	std::map<std::pair<int, int>, int> visited;

	for (int i = 0; i < N; ++i) {
		char D;
		int S;
		std::cin >> D >> S;

		int x = 0, y = 0;
		switch (D) {
		case 'N':
			y = 1;
			break;
		case 'E':
			x = 1;
			break;
		case 'S':
			y = -1;
			break;
		case 'W':
			x = -1;
			break;
		}

		for (int j = 0; j < S; ++j) {
			++time;
			pos.first += x;
			pos.second += y;

			if (visited[pos])
				ans = std::min(ans, time - visited[pos]);
			visited[pos] = time;
		}
	}

	std::cout << (ans == 1e9 ? -1 : ans) << std::endl;

	return 0;
}
