#include <algorithm>
#include <iostream>
#include <vector>

int N, Q;
std::vector<int> haybales;

int search(int x) {
	int low = 0, high = N;

	while (low < high) {
		int mid = (low + high) / 2;

		if (haybales[mid] <= x)
			low = mid + 1;
		else
			high = mid;
	}

	return low;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	std::cin >> N >> Q;
	haybales.assign(N, 0);

	for (int &x : haybales)
		std::cin >> x;

	std::sort(haybales.begin(), haybales.end());

	while (Q--) {
		int A, B;
		std::cin >> A >> B;

		std::cout << search(B) - search(A - 1) << std::endl;
	}

	return 0;
}
