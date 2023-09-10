#include <iostream>
#include <vector>

struct Point {
	long long x, y;
};

int N, K, A, B;
std::vector<Point> cities;

long long cost(Point a, Point b) {
	return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

bool is_equal(Point a, Point b) { return a.x == b.x && a.y == b.y; }

void solve() {
	std::cin >> N >> K >> A >> B;
	cities.clear();

	for (int i = 0; i < N; ++i) {
		int X, Y;
		std::cin >> X >> Y;

		cities.push_back({X, Y});
	}

	Point city_a = cities[A - 1], city_b = cities[B - 1];
	Point closest_a = city_b, closest_b = city_a;

	for (int i = 0; i < K; ++i) {
		Point city = cities[i];

		if (cost(city, city_a) < cost(closest_a, city_a))
			closest_a = city;
		if (cost(city, city_b) < cost(closest_b, city_b))
			closest_b = city;
	}

	std::cout << std::min(cost(city_a, closest_a) + cost(city_b, closest_b),
			      cost(city_a, city_b))
		  << std::endl;
	;
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
