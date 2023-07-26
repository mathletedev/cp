#include <iostream>
#include <queue>

int N, M;
std::queue<int> cities;
std::queue<int> towers;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int A;
		std::cin >> A;
		cities.push(A);
	}
	for (int i = 0; i < M; ++i) {
		int B;
		std::cin >> B;
		towers.push(B);
	}

	int R = 0;
	int prev_tower = towers.front();

	for (int i = 0; i < N; ++i) {
		while (towers.front() < cities.front() && towers.size() > 1) {
			prev_tower = towers.front();
			towers.pop();
		}

		int min_dist =
		    std::min(std::abs(cities.front() - prev_tower),
			     std::abs(towers.front() - cities.front()));

		R = std::max(R, min_dist);
		cities.pop();
	}

	std::cout << R << std::endl;

	return 0;
}
