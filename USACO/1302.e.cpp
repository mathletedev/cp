#include <iostream>
#include <vector>

struct Customer {
	int a, b, c;
};

int N, TC, TM;
std::vector<Customer> customers;

bool is_possible(int x) {
	for (int i = 0; i <= x; ++i) {
		int tc = TC - i;
		int tm = TM - (x - i);

		if (tc <= 0 || tm <= 0)
			continue;

		bool sad = 0;
		for (Customer c : customers) {
			if (c.a * tc + c.b * tm > c.c)
				sad = 1;
		}

		if (!sad)
			return 1;
	}

	return 0;
}

void solve() {
	std::cin >> N >> TC >> TM;

	for (int i = 0; i < N; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;

		customers.push_back({a, b, c});
	}

	int low = 0, high = TC + TM - 2;
	while (low < high) {
		int mid = (low + high) / 2;

		if (is_possible(mid))
			high = mid;
		else
			low = mid + 1;
	}

	std::cout << low << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
