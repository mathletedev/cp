#include <algorithm>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> A;

int sum(int i, int j) {
	int i_and_j, i_or_j;

	std::cout << "and " << i << " " << j << std::endl;
	std::cout.flush();
	std::cin >> i_and_j;

	std::cout << "or " << i << " " << j << std::endl;
	std::cout.flush();
	std::cin >> i_or_j;

	int i_xor_j = ~i_and_j & i_or_j;
	return 2 * i_and_j + i_xor_j;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	A.assign(N, 0);

	int a_plus_b = sum(1, 2);
	int b_plus_c = sum(2, 3);
	int a_plus_c = sum(1, 3);

	int a_minus_c = a_plus_b - b_plus_c;
	int a = (a_plus_c + a_minus_c) / 2;

	A[0] = a;
	A[1] = a_plus_b - a;
	A[2] = a_plus_c - a;

	for (int i = 3; i < N; ++i)
		A[i] = sum(i, i + 1) - A[i - 1];

	std::sort(A.begin(), A.end());

	std::cout << "finish " << A[K - 1] << std::endl;

	return 0;
}
