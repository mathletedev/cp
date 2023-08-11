#include <iostream>
#include <vector>

int N, X;
std::vector<int> A;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> X;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	int left = 0, right = 0, curr_sum = A[0], ans = 0;
	while (right < N) {
		if (curr_sum < X)
			curr_sum += A[++right];
		else if (curr_sum > X)
			curr_sum -= A[left++];
		else
			++ans, curr_sum += A[++right] - A[left++];
	}

	std::cout << ans << std::endl;

	return 0;
}
