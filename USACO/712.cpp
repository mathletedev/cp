#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("circlecross.in", "r", stdin);
	freopen("circlecross.out", "w", stdout);

	std::string cows;
	std::cin >> cows;

	std::vector<int> start(26, -1), end(26, -1);

	for (int i = 0; i < 52; ++i) {
		if (start[cows[i] - 'A'] == -1)
			start[cows[i] - 'A'] = i;
		else
			end[cows[i] - 'A'] = i;
	}

	int count = 0;

	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < 26; ++j) {
			if (start[i] < start[j] && start[j] < end[i] &&
			    end[i] < end[j])
				++count;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
