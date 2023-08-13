#include <iostream>
#include <vector>

struct Edge {
	int cow, next;
	bool is_favourite;
};

int N, M;
std::vector<std::vector<Edge>> adj;
std::vector<bool> visited, visited_cycle;
int root, extra_edge;
std::vector<int> perm;
std::vector<bool> hungry;

void dfs_cycle(int node, int prev) {
	visited_cycle[node] = 1;

	for (Edge u : adj[node]) {
		if (visited_cycle[u.next]) {
			if (root == -1 && u.next != prev) {
				root = u.is_favourite ? node : u.next;

				extra_edge = u.cow;
				perm.push_back(u.cow);
				hungry[u.cow] = 0;
			}

			continue;
		}

		dfs_cycle(u.next, node);
	}
}

void dfs(int node) {
	visited[node] = 1;

	for (Edge u : adj[node]) {
		if (!visited[u.next] && u.cow != extra_edge) {
			perm.push_back(u.cow);
			hungry[u.cow] = 0;

			dfs(u.next);
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	adj.assign(M, std::vector<Edge>());
	visited.assign(M, 0);
	visited_cycle.assign(M, 0);
	hungry.assign(N, 1);

	for (int i = 0; i < N; ++i) {
		int F, S;
		std::cin >> F >> S, --F, --S;

		adj[F].push_back({i, S, 1});
		adj[S].push_back({i, F, 0});
	}

	for (int i = 0; i < M; ++i) {
		if (!visited[i]) {
			root = -1, extra_edge = -1;
			dfs_cycle(i, -1);

			dfs(root == -1 ? i : root);
		}
	}

	int ans = 0;
	for (int i = 0; i < N; ++i) {
		if (hungry[i])
			++ans, perm.push_back(i);
	}

	std::cout << ans << std::endl;
	for (int i = 0; i < N; ++i)
		std::cout << perm[i] + 1 << std::endl;

	return 0;
}
