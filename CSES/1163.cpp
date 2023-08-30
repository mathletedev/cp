#include <iostream>
#include <set>

int X, N;
std::set<int> lights;
std::multiset<int> dists;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> X >> N;

	lights.insert(0);
	lights.insert(X);
	dists.insert(X);

	for (int i = 0; i < N; ++i) {
		int P;
		std::cin >> P;

		auto next = lights.upper_bound(P);
		auto prev = next;
		--prev;

		dists.erase(dists.find(*next - *prev));
		dists.insert(P - *prev);
		dists.insert(*next - P);

		auto ans = dists.end();
		--ans;
		std::cout << *ans << " ";

		lights.insert(P);
	}

	std::cout << std::endl;

	return 0;
}
