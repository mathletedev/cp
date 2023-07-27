#include <algorithm>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;

bool is_possible(int x) {
	long long sum = 0;
	for (int a : A)
		sum += std::max(0, x - a);

	return sum <= K;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	std::sort(A.begin(), A.end());
	A.erase(A.begin(), A.begin() + N / 2);

	long long low = 0, high = 2e9;
	while (low < high) {
		int mid = (low + high) / 2 + (low + high) % 2;

		if (is_possible(mid))
			low = mid;
		else
			high = mid - 1;
	}

	std::cout << low << std::endl;

	return 0;
}
