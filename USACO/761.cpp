#include <cstdio>
#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	int n;
	std::cin >> n;

	std::vector<int> bessie(100, 7), elsie(100, 7), mildred(100, 7);

	while (n--) {
		int d, m;
		std::string n;
		std::cin >> d >> n >> m;

		std::vector<int> *cow;

		if (n == "Bessie")
			cow = &bessie;
		else if (n == "Elsie")
			cow = &elsie;
		else if (n == "Mildred")
			cow = &mildred;

		for (int i = d - 1; i < 100; ++i)
			(*cow)[i] += m;
	}

	// state of the wall
	// 0 = b, e, m
	// 1 = b, e
	// 2 = b, m
	// 3 = e, m
	// 4 = b
	// 5 = e
	// 6 = m

	int state = 0, count = 0;

	for (int i = 0; i < 100; ++i) {
		int newState, b = bessie[i], e = elsie[i], m = mildred[i];

		if (b == e && e == m)
			newState = 0;
		else if (b == e && b > m)
			newState = 1;
		else if (b == m && b > e)
			newState = 2;
		else if (e == m && e > b)
			newState = 3;
		else if (b > e && b > m)
			newState = 4;
		else if (e > b && e > m)
			newState = 5;
		else
			newState = 6;

		if (newState != state) {
			++count;
			state = newState;
		}
	}

	std::cout << count << std::endl;

	return 0;
}
