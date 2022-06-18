#include <cmath>
#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		float n;
		std::cin >> n;

		int p2 = round(n / 3);
		int p3 = p2 - 1;
		int p1 = n - p2 - p3;

		bool e = true;
		while (p1 <= p2) {
			if (e)
				p3--;
			else
				p2--;
			p1++;
		}

		std::cout << p2 << " " << p1 << " " << p3 << std::endl;
	}

	return 0;
}
