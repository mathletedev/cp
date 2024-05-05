#include <algorithm>
#include <iostream>
#include <vector>

int N, Q;
std::vector<int> C;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> Q;
	C.assign(N, 0);

	for (int &x : C)
		std::cin >> x;

	for (int i = 0; i < N; ++i) {
		int T;
		std::cin >> T;

		C[i] -= T;
	}

	std::sort(C.begin(), C.end());

	for (int i = 0; i < Q; ++i) {
		int V, S;
		std::cin >> V >> S;

		int low = 0, high = N;
		while (low < high) {
			int mid = (low + high) / 2;

			if (C[mid] < S)
				high = mid;
			else
				low = mid + 1;
		}

		std::cout << (low < V ? "NO" : "YES") << std::endl;
	}

	return 0;
}
