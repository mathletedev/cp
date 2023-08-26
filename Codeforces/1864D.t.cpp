#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> matrix;

void solve() {
	std::cin >> N;
	matrix.assign(N, std::vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			char x;
			std::cin >> x;

			matrix[i][j] = x - '0';
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (matrix[i][j] == 1) {
				matrix[i][j] = 0;
				++ans;

				for (int k = i + 1; k < N; ++k) {
					for (int l = 0; l < N; ++l)
						if (k - i >= std::abs(l - j))
							matrix[k][l] ^= 1;
				}
			}
		}
	}

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
