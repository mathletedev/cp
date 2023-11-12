#include <iostream>
#include <vector>

struct DSU {
	std::vector<int> e;

	DSU(int n) { e.assign(n, -1); }

	int comp(int x) { return e[x] < 0 ? x : e[x] = comp(e[x]); }
	bool same_set(int x, int y) { return comp(x) == comp(y); }
	int size(int x) { return -e[comp(x)]; }
	bool unite(int x, int y) {
		x = comp(x), y = comp(y);
		if (x == y)
			return 0;
		if (e[x] > e[y])
			std::swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};

int N, M;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;

	DSU dsu(N);

	int num_comp = N;
	int max_comp = 0;

	for (int i = 0; i < M; ++i) {
		int A, B;
		std::cin >> A >> B;
		--A, --B;

		if (dsu.unite(A, B))
			--num_comp;
		max_comp = std::max(max_comp, dsu.size(A));

		std::cout << num_comp << " " << max_comp << std::endl;
	}

	return 0;
}
