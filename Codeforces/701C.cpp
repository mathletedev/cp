#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int N;
std::vector<char> pokemon;
std::unordered_set<char> types;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	pokemon.assign(N, 0);

	for (char &x : pokemon)
		std::cin >> x, types.insert(x);

	int left = 0, right = 0, ans = 1e9;
	std::unordered_map<char, int> caught;
	caught[pokemon[0]] = 1;

	while (right < N) {
		if (caught.size() < types.size())
			++caught[pokemon[++right]];
		else {
			ans = std::min(ans, right - left + 1);

			int type = pokemon[left++];
			if (--caught[type] == 0)
				caught.erase(type);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
