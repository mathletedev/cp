#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("buckets.in", "r", stdin);
	freopen("buckets.out", "w", stdout);

	int bX, bY, rX, rY, lX, lY;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 11; ++j) {
			switch (getchar()) {
			case 'B':
				bX = i;
				bY = j;
				break;
			case 'R':
				rX = i;
				rY = j;
				break;
			case 'L':
				lX = i;
				lY = j;
				break;
			}
		}
	}

	int p = std::abs(bX - lX) + std::abs(bY - lY) - 1;
	if ((bX == rX && rX == lX && (rY - bY) * (rY - lY) < 0) ||
	    (bY == rY && rY == lY && (rX - bX) * (rX - lX) < 0))
		p += 2;

	std::cout << p << std::endl;

	return 0;
}
