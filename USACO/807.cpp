#include <cmath>
#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);

	int a, b, x, y;
	std::cin >> a >> b >> x >> y;

	int tN = std::abs(a - b);
	int tX = std::abs(a - x) + std::abs(b - y);
	int tY = std::abs(a - y) + std::abs(b - x);

	std::cout << std::min(tN, std::min(tX, tY)) << std::endl;

	return 0;
}
