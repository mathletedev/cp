#include <cstdint>
#include <cstdio>
#include <iostream>
#include <unordered_map>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("notlast.in", "r", stdin);
	freopen("notlast.out", "w", stdout);

	int n;
	std::cin >> n;

	std::unordered_map<std::string, int> cows;
	cows["Bessie"] = 0;
	cows["Elsie"] = 0;
	cows["Daisy"] = 0;
	cows["Gertie"] = 0;
	cows["Annabelle"] = 0;
	cows["Maggie"] = 0;
	cows["Henrietta"] = 0;

	while (n--) {
		std::string name;
		int milk;
		std::cin >> name >> milk;

		cows[name] += milk;
	}

	int lowest = INT32_MAX;
	for (std::pair<std::string, int> cow : cows)
		lowest = std::min(lowest, cow.second);

	int second = INT32_MAX;
	std::string name = "Tie";
	for (std::pair<std::string, int> cow : cows) {
		if (cow.second > lowest && cow.second < second) {
			second = cow.second;
			name = cow.first;
		} else if (cow.second == second)
			name = "Tie";
	}

	std::cout << name << std::endl;

	return 0;
}
