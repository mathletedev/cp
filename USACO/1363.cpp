#include <algorithm>
#include <iostream>
#include <vector>

int N;
std::vector<int> potions;
std::vector<std::vector<int>> adj;
std::vector<int> rev;
std::vector<int> count;
std::vector<int> depth;

int dfs(int node, int curr_depth) {
	depth[node] = curr_depth;

	if (adj[node].size() == 0) {
		count[node] = 1;
		return 1;
	}

	for (int u : adj[node])
		count[node] += dfs(u, curr_depth + 1);

	return count[node];
}

void dfs2(int node) {
	if (node == 0)
		return;

	--count[node];
	dfs2(rev[node]);
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;
	potions.assign(N, 0);
	adj.assign(N + 1, std::vector<int>());
	rev.assign(N + 1, 0);
	count.assign(N + 1, 0);
	depth.assign(N + 1, 0);

	for (int &x : potions)
		std::cin >> x;

	for (int i = 0; i < N - 1; ++i) {
		int A, B;
		std::cin >> A >> B;

		adj[A].push_back(B);
		rev[B] = A;
	}

	int trav = dfs(1, 0);

	std::vector<std::pair<int, int>> rem;
	for (int i = 0; i < trav; ++i)
		rem.push_back({N - depth[potions[i]], potions[i]});

	int ans = 0;
	for (int i = 0; i < trav; ++i) {
		if (count[rem[i].second] > 0) {
			++ans;
			dfs2(rem[i].second);
		}
	}

	std::cout << ans << std::endl;

	return 0;
}
