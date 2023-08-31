#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

struct Cow {
	int a, t;
	int sen;
};

int N;
std::vector<Cow> cows;
std::set<std::pair<int, int>> waiting;

bool cmp(Cow a, Cow b) { return a.a < b.a; }

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);

	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int A, T;
		std::cin >> A >> T;

		cows.push_back({A, T, i});
	}

	std::sort(cows.begin(), cows.end(), cmp);

	int ans = 0, curr = 0, time = 0;

	while (curr < N || !waiting.empty()) {
		if (curr < N && cows[curr].a <= time) {
			waiting.insert({cows[curr].sen, curr});
			++curr;
		} else if (waiting.empty()) {
			time = cows[curr].a + cows[curr].t;
			++curr;
		} else {
			Cow cow = cows[(*waiting.begin()).second];
			ans = std::max(ans, time - cow.a);

			time += cow.t;
			waiting.erase(waiting.begin());
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
