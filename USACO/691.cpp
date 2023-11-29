#include <iostream>
#include <vector>

int N;
std::vector<int> seq;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	std::cin >> N;
	seq.assign(N, 0);
	std::vector<int> rev(N);

	for (int i = 0; i < N; ++i) {
		char c;
		std::cin >> c;

		int x;
		switch (c) {
		case 'H':
			x = 0;
			break;
		case 'P':
			x = 1;
			break;
		case 'S':
			x = 2;
			break;
		}

		seq[i] = rev[N - 1 - i] = x;
	}

	std::vector<std::vector<int>> prefix(3, std::vector<int>(N + 1));
	std::vector<std::vector<int>> suffix(3, std::vector<int>(N + 1));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 3; ++j) {
			prefix[j][i + 1] = prefix[j][i];
			suffix[j][i + 1] = suffix[j][i];
		}

		++prefix[seq[i]][i + 1];
		++suffix[rev[i]][i + 1];
	}

	int ans = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			for (int k = 0; k <= N; ++k)
				ans = std::max(ans,
					       prefix[i][k] + suffix[j][N - k]);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
