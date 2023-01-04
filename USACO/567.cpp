#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);

	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	if (b < c || d < a)
		std::cout << b - a + d - c << std::endl;
	else
		std::cout << std::max(b, d) - std::min(a, c) << std::endl;

	return 0;
}
