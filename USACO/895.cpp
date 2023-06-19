#include <cstdint>
#include <cstdio>
#include <iostream>
#include <vector>

int N;
std::vector<std::vector<bool>> grid;
std::vector<std::vector<bool>> visited;
int area = 0;
int perimeter = 0;

void ff(int r, int c) {
	if (visited[r][c])
		return;

	visited[r][c] = true;
	++area;

	int p = 4;
	if (c + 1 < N && grid[r][c + 1]) {
		--p;
		ff(r, c + 1);
	}
	if (c - 1 >= 0 && grid[r][c - 1]) {
		--p;
		ff(r, c - 1);
	}
	if (r + 1 < N && grid[r + 1][c]) {
		--p;
		ff(r + 1, c);
	}
	if (r - 1 >= 0 && grid[r - 1][c]) {
		--p;
		ff(r - 1, c);
	}

	perimeter += p;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	std::cin >> N;
	grid.resize(N);
	visited.resize(N);

	for (int i = 0; i < N; ++i) {
		grid[i].resize(N);
		visited[i].resize(N);

		for (int j = 0; j < N; ++j) {
			char c;
			std::cin >> c;

			grid[i][j] = c == '#';
		}
	}

	int maxA = 0;
	int minP = INT32_MAX;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (grid[i][j] && !visited[i][j]) {
				area = 0;
				perimeter = 0;

				ff(i, j);

				if (area > maxA) {
					maxA = area;
					minP = perimeter;
				} else if (area == maxA)
					minP = std::min(minP, perimeter);
			}
		}
	}

	std::cout << maxA << " " << minP << std::endl;

	return 0;
}
