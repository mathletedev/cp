#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<char>> spotty;
	std::vector<std::vector<char>> plain;

	for (int i = 0; i < n; ++i) {
		std::vector<char> genomes;
		for (int j = 0; j < m; ++j) {
			char c;
			std::cin >> c;
			genomes.push_back(c);
		}
		spotty.push_back(genomes);
	}

	for (int i = 0; i < n; ++i) {
		std::vector<char> genomes;
		for (int j = 0; j < m; ++j) {
			char c;
			std::cin >> c;
			genomes.push_back(c);
		}
		plain.push_back(genomes);
	}

	int count = 0;

	for (int i = 0; i < m; ++i) {
		std::unordered_set<char> sl;
		std::unordered_set<char> pl;
		for (int j = 0; j < n; ++j) {
			sl.insert(spotty[j][i]);
			pl.insert(plain[j][i]);
		}

		std::vector<char> chars = {'A', 'C', 'G', 'T'};
		for (char &c : chars) {
			if (sl.count(c) && pl.count(c))
				goto found;
		}

		count++;
	found:;
	}

	std::cout << count << std::endl;

	return 0;
}
