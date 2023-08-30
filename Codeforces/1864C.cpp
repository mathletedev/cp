#include <iostream>
#include <set>

int X;

void solve() {
	std::cin >> X;

	std::set<int> ans;

	int pow2 = 1;
	ans.insert(pow2);
	while (pow2 * 2 < X) {
		pow2 *= 2;
		ans.insert(pow2);
	}

	int curr = pow2, step = pow2;
	while (curr < X) {
		while (step > X - curr)
			step /= 2;
		curr += step;
		ans.insert(curr);
	}

	std::cout << ans.size() << std::endl;
	std::set<int>::reverse_iterator itr;
	for (itr = ans.rbegin(); itr != ans.rend(); ++itr)
		std::cout << *itr << " ";
	std::cout << std::endl;
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
