#include <iostream>
#include <vector>

int N;
std::vector<int> P;
std::vector<int> ans;
bool in_cycle;

void traverse(int node) {
	if (ans[node] != -2) {
		if (ans[node] == -1)
			ans[node] = node, in_cycle = 1;
		return;
	}

	ans[node] = -1;
	traverse(P[node]);

	if (ans[node] != -1) {
		in_cycle = 0;
		return;
	}

	ans[node] = in_cycle ? node : ans[P[node]];
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::cin >> N;
	P.resize(N);
	ans.assign(N, -2);

	for (int &i : P)
		std::cin >> i, --i;

	for (int i = 0; i < N; ++i)
		traverse(i);

	for (int i : ans)
		std::cout << i + 1 << std::endl;

	return 0;
}
