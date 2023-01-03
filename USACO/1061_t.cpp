#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::vector<std::tuple<int, char, int, int>> cows;
	std::vector<int> eaten(n, 0);
	int maxX = 0, maxY = 0;

	for (int i = 0; i < n; ++i) {
		char d;
		int x, y;
		std::cin >> d >> x >> y;

		cows.push_back(std::make_tuple(i, d, x, y));

		if (d == 'N')
			maxX = std::max(maxX, x);
		else
			maxY = std::max(maxY, y);
	}

	std::vector<std::pair<int, int>> rut;

	while (cows.size()) {
		std::vector<std::pair<int, int>> newRut = rut;

		for (int i = 0; i < cows.size(); ++i) {
			std::pair<int, int> pos = {std::get<2>(cows[i]),
						   std::get<3>(cows[i])};

			if (std::find(rut.begin(), rut.end(), pos) !=
			    rut.end()) {
				cows.erase(cows.begin() + i);
				--i;
				continue;
			}

			newRut.push_back(pos);

			if ((std::get<1>(cows[i]) == 'N' &&
			     std::get<3>(cows[i]) > maxY) ||
			    (std::get<1>(cows[i]) == 'E' &&
			     std::get<2>(cows[i]) > maxX)) {
				eaten[std::get<0>(cows[i])] = -1;
				cows.erase(cows.begin() + i);
				--i;
				continue;
			}

			if (std::get<1>(cows[i]) == 'N')
				++std::get<3>(cows[i]);
			else
				++std::get<2>(cows[i]);

			++eaten[std::get<0>(cows[i])];
		}

		rut = newRut;
	}

	for (int amount : eaten) {
		if (amount == -1)
			std::cout << "Infinity" << std::endl;
		else
			std::cout << amount << std::endl;
	}

	return 0;
}
