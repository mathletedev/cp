#include <iostream>
#include <vector>

int N;
std::vector<int> B;

void solve() {
	std::cin >> N;
	B.assign(N, 0);

	for (int &x : B)
		std::cin >> x;

	std::vector<int> A;
	A.push_back(B[0]);

	for (int i = 1; i < N; ++i) {
		if (B[i - 1] > B[i])
			A.push_back(1);
		A.push_back(B[i]);
	}

	std::cout << A.size() << std::endl;
	for (int x : A)
		std::cout << x << " ";
	std::cout << std::endl;
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
