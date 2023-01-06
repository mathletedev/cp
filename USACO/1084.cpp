#include <iostream>

int solve(int evens, int odds) {
	if (evens < odds)
		return solve(evens + 1, odds - 2);
	else if (evens == odds)
		return evens * 2;
	else
		return odds * 2 + 1;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	int evens = 0, odds = 0;

	while (n--) {
		int id;
		std::cin >> id;

		if (id % 2 == 0)
			++evens;
		else
			++odds;
	}

	std::cout << solve(evens, odds) << std::endl;

	return 0;
}
