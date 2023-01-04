#include <cstdio>
#include <iostream>

struct Rect {
	int x1, y1, x2, y2;
	int area() { return (x2 - x1) * (y2 - y1); }
};

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	Rect a, b;

	std::cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
	std::cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;

	int initial = a.area();

	if (b.x1 <= a.x1 && b.x2 >= a.x2 &&
	    ((b.y1 < a.y2 && b.y2 >= a.y2) || (b.y2 > a.y1 && b.y1 <= a.y1))) {
		Rect overlap;
		overlap.x1 = a.x1;
		overlap.y1 = std::max(b.y1, a.y1);
		overlap.x2 = a.x2;
		overlap.y2 = std::min(b.y2, a.y2);

		initial -= overlap.area();
	}

	if (b.y1 <= a.y1 && b.y2 >= a.y2 &&
	    ((b.x1 < a.x2 && b.x2 >= a.x2) || (b.x2 > a.x1 && b.x1 <= a.x1))) {
		Rect overlap;
		overlap.x1 = std::max(b.x1, a.x1);
		overlap.y1 = a.y1;
		overlap.x2 = std::min(b.x2, a.x2);
		overlap.y2 = a.y2;

		initial -= overlap.area();
	}

	std::cout << std::max(0, initial) << std::endl;

	return 0;
}
