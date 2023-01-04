#include <cstdio>
#include <iostream>
#include <tuple>

int area(std::tuple<int, int, int, int> coords) {
	if (std::get<0>(coords) > std::get<2>(coords) ||
	    std::get<1>(coords) > std::get<3>(coords))
		return 0;

	return (std::get<2>(coords) - std::get<0>(coords)) *
	       (std::get<3>(coords) - std::get<1>(coords));
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("billboard.in", "r", stdin);
	freopen("billboard.out", "w", stdout);

	std::tuple<int, int, int, int> bb1, bb2, truck;

	int x1, y1, x2, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;
	bb1 = std::make_tuple(x1, y1, x2, y2);

	std::cin >> x1 >> y1 >> x2 >> y2;
	bb2 = std::make_tuple(x1, y1, x2, y2);

	std::cin >> x1 >> y1 >> x2 >> y2;
	truck = std::make_tuple(x1, y1, x2, y2);

	int initial = area(bb1) + area(bb2);

	initial -= area(
	    std::make_tuple(std::max(std::get<0>(truck), std::get<0>(bb1)),
			    std::max(std::get<1>(truck), std::get<1>(bb1)),
			    std::min(std::get<2>(truck), std::get<2>(bb1)),
			    std::min(std::get<3>(truck), std::get<3>(bb1))));

	initial -= area(
	    std::make_tuple(std::max(std::get<0>(truck), std::get<0>(bb2)),
			    std::max(std::get<1>(truck), std::get<1>(bb2)),
			    std::min(std::get<2>(truck), std::get<2>(bb2)),
			    std::min(std::get<3>(truck), std::get<3>(bb2))));

	std::cout << initial << std::endl;

	return 0;
}
