#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::vector<std::vector<int>> towers(n);
	std::vector<int> blocks;

	for (int i = 0; i < n; ++i) {
		int k;
		std::cin >> k;

		std::vector<int> tower(k);
		for (int j = 0; j < k; ++j) {
			int b;
			std::cin >> b;

			tower[j] = b;
			blocks.push_back(b);
		}

		std::reverse(tower.begin(), tower.end());
		towers[i] = tower;
	}

	std::sort(blocks.begin(), blocks.end(), std::greater<int>());

	int s = 0, c = 0;
	std::vector<int> final;

	for (int b = 0; b < blocks.size(); ++b) {
		if (final.size() > b) {
			if (final[b] == blocks[b])
				continue;

			++s;
			std::vector<int> rem(final.begin() + b, final.end());
			towers.push_back(rem);
			final.erase(final.begin() + b, final.end());
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < towers[i].size(); ++j) {
				if (towers[i][j] == blocks[b]) {
					if (final.size())
						++c;
					if (j > 0)
						++s;
					final.insert(final.end(),
						     towers[i].begin() + j,
						     towers[i].end());
					towers[i].erase(towers[i].begin() + j,
							towers[i].end());
					goto next;
				}
			}
		}

	next:;
	}

	std::cout << s << " " << c << std::endl;

	return 0;
}
