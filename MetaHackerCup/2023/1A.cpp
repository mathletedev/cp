#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

int N;
std::vector<double> X;

void solve() {
	std::cin >> N;
	X.assign(N, 0);

	for (double &x : X)
		std::cin >> x;

	std::sort(X.begin(), X.end());

	if (N != 5) {
		std::cout << (X[N - 1] + X[N - 2]) / 2 - (X[0] + X[1]) / 2
			  << std::endl;
		return;
	}

	double left = (X[N - 1] + X[N - 2]) / 2 - (X[0] + X[2]) / 2;
	double right = (X[N - 1] + X[N - 3]) / 2 - (X[0] + X[1]) / 2;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << std::max(left, right) << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	for (int i = 1; i <= T; ++i) {
		std::cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
