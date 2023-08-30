#include <iostream>
#include <set>

int N, M;
std::multiset<int> tickets;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int H;
		std::cin >> H;

		tickets.insert(H);
	}

	for (int i = 0; i < M; ++i) {
		int T;
		std::cin >> T;

		std::multiset<int>::iterator it = tickets.upper_bound(T);
		if (it != tickets.begin()) {
			--it;
			std::cout << *it << std::endl;
			tickets.erase(tickets.find(*it));
		} else
			std::cout << -1 << std::endl;
	}

	return 0;
}
