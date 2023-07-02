#include <iostream>
#include <vector>

int N;
std::vector<std::vector<char>> grid;
std::vector<std::vector<bool>> visited;

struct PCL {
	int i1, j1, i2, j2;
};

void ff(int i1, int j1, int i2, int j2, int i, int j, char c) {
	if ((i < i1 || i > i2 || j < j1 || j > j2) || grid[i][j] != c ||
	    visited[i][j])
		return;

	visited[i][j] = true;

	ff(i1, j1, i2, j2, i + 1, j, c);
	ff(i1, j1, i2, j2, i - 1, j, c);
	ff(i1, j1, i2, j2, i, j + 1, c);
	ff(i1, j1, i2, j2, i, j - 1, c);
}

bool cc(int i1, int j1, int i2, int j2) {
	std::fill(visited.begin(), visited.end(), std::vector<bool>(N, false));
	int count = 0;
	std::vector<int> colours = std::vector<int>(26, 0);

	for (int i = i1; i <= i2; ++i) {
		for (int j = j1; j <= j2; ++j) {
			if (visited[i][j])
				continue;

			if (colours[grid[i][j] - 'A'] == 0)
				++count;
			++colours[grid[i][j] - 'A'];

			ff(i1, j1, i2, j2, i, j, grid[i][j]);
		}
	}

	if (count != 2)
		return false;

	bool primary = false, secondary = false;
	for (int i = 0; i < 26; ++i) {
		if (colours[i] == 1)
			primary = true;
		if (colours[i] > 1)
			secondary = true;
	}

	return primary && secondary;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);

	std::cin >> N;
	grid.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; ++i) {
		grid[i].resize(N);
		for (int j = 0; j < N; ++j) {
			char c;
			std::cin >> c;

			grid[i][j] = c;
		}
	}

	std::vector<PCL> pcls;
	int count = 0;

	for (int i1 = 0; i1 < N; ++i1) {
		for (int j1 = 0; j1 < N; ++j1) {
			for (int i2 = i1; i2 < N; ++i2) {
				for (int j2 = j1; j2 < N; ++j2) {
					if (cc(i1, j1, i2, j2))
						pcls.push_back(
						    {i1, j1, i2, j2});
				}
			}
		}
	}

	for (int i = 0; i < pcls.size(); ++i) {
		for (int j = 0; j < pcls.size(); ++j) {
			if (j == i)
				continue;

			if (pcls[j].i1 <= pcls[i].i1 &&
			    pcls[j].j1 <= pcls[i].j1 &&
			    pcls[j].i2 >= pcls[i].i2 &&
			    pcls[j].j2 >= pcls[i].j2)
				goto skip;
		}

		++count;

	skip:;
	}

	std::cout << count << std::endl;

	return 0;
}
