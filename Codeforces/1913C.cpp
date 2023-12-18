#include <iostream>
#include <map>

int T, V;
std::map<int, int> m;

void solve() {
	std::cin >> T >> V;

	if (T == 1) {
		++m[1 << V];
		return;
	}

	for (auto it = m.rbegin(); it != m.rend(); ++it)
		V -= it->first * std::min(V / it->first, it->second);

	std::cout << (V == 0 ? "YES" : "NO") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int M;
	std::cin >> M;

	while (M--)
		solve();

	return 0;
}
