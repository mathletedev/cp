#include <iostream>
#include <vector>

int N, T;
std::vector<int> A;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> T;
	A.assign(N, 0);

	for (int &x : A)
		std::cin >> x;

	int left = 0, right = 0, time = 0, max_books = 0;

	while (left < N) {
		while (right < N) {
			time += A[right];
			++right;

			if (time > T) {
				--right;
				time -= A[right];
				break;
			}
		}

		max_books = std::max(max_books, right - left);
		time -= A[left];
		++left;
	}

	std::cout << max_books << std::endl;

	return 0;
}
