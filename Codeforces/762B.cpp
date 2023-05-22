#include <algorithm>
#include <iostream>
#include <vector>

bool cmp(std::pair<int, std::string> a, std::pair<int, std::string> b) {
	return a.first < b.first;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int A, B, C, M;
	std::cin >> A >> B >> C >> M;

	std::vector<std::pair<int, std::string>> mice(M);
	for (int i = 0; i < M; ++i) {
		int val;
		std::string type;
		std::cin >> val >> type;

		mice[i] = {val, type};
	}

	std::sort(mice.begin(), mice.end(), cmp);

	long long cost = 0, a = 0, b = 0, c = 0;

	for (auto &mouse : mice) {
		if (mouse.second == "USB" && a < A) {
			++a;
			cost += mouse.first;
		} else if (mouse.second == "PS/2" && b < B) {
			++b;
			cost += mouse.first;
		} else if (c < C) {
			++c;
			cost += mouse.first;
		}
	}

	std::cout << a + b + c << " " << cost << std::endl;
}
