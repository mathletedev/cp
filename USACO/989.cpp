#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);

	int k, n;
	std::cin >> k >> n;

	while (n--) {
		int x;
		std::cin >> x;

		int time = 0, speed = 0, dist = 0;

		for (;;) {
			++time;
			++speed;
			dist += speed;
			if (dist >= k) {
				std::cout << time << std::endl;
				break;
			}

			if (speed >= x) {
				++time;
				dist += speed;
				if (dist >= k) {
					std::cout << time << std::endl;
					break;
				}
			}
		}
	}

	return 0;
}
