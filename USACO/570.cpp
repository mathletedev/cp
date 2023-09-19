#include <iostream>
#include <map>
#include <queue>
#include <vector>

int N, M;
std::vector<std::vector<bool>> visited, lit;
std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> switches;
int ans = 1;

void dfs(std::pair<int, int> node) {
	if (visited[node.first][node.second] || !lit[node.first][node.second])
		return;
	visited[node.first][node.second] = 1;

	for (std::pair<int, int> next : switches[node]) {
		if (!lit[next.first][next.second]) {
			lit[next.first][next.second] = 1;
			++ans;
		}

		if ((next.first > 0 && visited[next.first - 1][next.second]) ||
		    (next.first < N && visited[next.first + 1][next.second]) ||
		    (next.first > 0 && visited[next.first][next.second - 1]) ||
		    (next.first < N && visited[next.first][next.second + 1]))
			dfs(next);
	}

	if (node.first > 1)
		dfs({node.first - 1, node.second});
	if (node.first < N)
		dfs({node.first + 1, node.second});
	if (node.second > 1)
		dfs({node.first, node.second - 1});
	if (node.second < N)
		dfs({node.first, node.second + 1});
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

	std::cin >> N >> M;
	lit.assign(N + 1, std::vector<bool>(N + 1, 0));
	visited.assign(N + 1, std::vector<bool>(N + 1, 0));

	for (int i = 0; i < M; ++i) {
		int X, Y, A, B;
		std::cin >> X >> Y >> A >> B;

		switches[{X, Y}].push_back({A, B});
	}

	lit[1][1] = 1;

	dfs({1, 1});

	std::cout << ans << std::endl;

	return 0;
}
