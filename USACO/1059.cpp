#include <algorithm>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n[7];
	for (int i = 0; i < 7; ++i)
		std::cin >> n[i];

	std::sort(n, n + 7);

	std::cout << n[0] << " " << n[1] << " " << n[6] - n[0] - n[1]
		  << std::endl;

	return 0;
}
