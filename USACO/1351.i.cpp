#include <algorithm>
#include <iostream>
#include <vector>

int N, K;
std::vector<int> A, B;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> K;
	A.assign(K, 0), B.assign(K, 0);

	int missing = N;
	std::vector<bool> seen(N + 1);

	for (int &x : A) {
		std::cin >> x;
		if (!seen[x])
			--missing, seen[x] = 1;
	}
	for (int &x : B) {
		std::cin >> x;
		if (!seen[x])
			--missing, seen[x] = 1;
	}

	std::vector<int> A_graph;
	for (int x : A) {
		if (std::find(B.begin(), B.end(), x) != B.end())
			A_graph.push_back(x);
	}
	std::vector<int> B_graph;
	for (int x : B) {
		if (std::find(A.begin(), A.end(), x) != A.end())
			B_graph.push_back(x);
	}

	int offset = std::find(B_graph.begin(), B_graph.end(), A_graph[0]) -
		     B_graph.begin();

	std::vector<int> new_B_graph;
	for (int i = 0; i < B_graph.size(); ++i)
		new_B_graph.push_back(B_graph[(i + offset) % B_graph.size()]);

	std::cout << A_graph.size() + missing << std::endl;

	return 0;
}
