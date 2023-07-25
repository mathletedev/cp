#include <iostream>
#include <queue>
#include <vector>

int C, N;
std::vector<int> teams;
std::vector<int> graph;
std::queue<int> queue;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> C >> N;
	teams.assign(N, 0);
	graph.assign(1 << C, INT32_MAX);

	for (int i = 0; i < N; ++i) {
		int binary = 0;
		int reverse = 0;

		for (int j = 0; j < C; ++j) {
			char c;
			std::cin >> c;

			(c == 'G' ? binary : reverse) += 1 << j;
		}

		teams[i] = binary;
		graph[reverse] = 0;
		queue.push(reverse);
	}

	while (!queue.empty()) {
		int node = queue.front();
		queue.pop();

		for (int i = 0; i < C; ++i) {
			int next = node ^ (1 << i);
			if (graph[next] != INT32_MAX)
				continue;

			graph[next] = graph[node] + 1;
			queue.push(next);
		}
	}

	for (int i = 0; i < N; ++i)
		std::cout << C - graph[teams[i]] << std::endl;

	return 0;
}
