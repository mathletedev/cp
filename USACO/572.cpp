#include <iostream>
#include <vector>

int N, Q;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	std::cin >> N >> Q;

	std::vector<std::vector<int>> prefix(4, std::vector<int>(N + 1));

	for (int i = 0; i < N; ++i) {
		int x;
		std::cin >> x;

		for (int j = 1; j <= 3; ++j)
			prefix[j][i + 1] = prefix[j][i];

		++prefix[x][i + 1];
	}

	for (int i = 0; i < Q; ++i) {
		int a, b;
		std::cin >> a >> b;

		for (int j = 1; j <= 3; ++j) {
			std::cout << prefix[j][b] - prefix[j][a - 1];
			if (j != 3)
				std::cout << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
