#include <iostream>
#include <vector>

int N, M;
std::vector<int> A;

void solve() {
	std::cin >> N >> M;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	int total_or = 0;
	for (int i = 0; i < M; ++i) {
		int B;
		std::cin >> B;

		total_or |= B;
	}

	int min = 0, max = 0;
	for (int x : A) {
		min ^= x;
		max ^= (x | total_or);
	}

	if (N % 2 == 0)
		std::swap(min, max);
	std::cout << min << " " << max << std::endl;
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
