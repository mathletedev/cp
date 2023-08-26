#include <iostream>
#include <set>
#include <vector>

int N, M;
std::vector<std::set<char>> carpet;

void solve() {
	std::cin >> N >> M;
	carpet.assign(M, {});

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char x;
			std::cin >> x;

			carpet[j].insert(x);
		}
	}

	int curr = 0;
	for (std::set<char> col : carpet) {
		if (curr == 4)
			break;
		if (col.find("vika"[curr]) != col.end())
			++curr;
	}

	std::cout << (curr == 4 ? "YES" : "NO") << std::endl;
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
