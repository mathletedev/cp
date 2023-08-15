#include <iostream>
#include <vector>

int N, M;
std::string S;
std::vector<std::vector<int>> colours;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N >> M;
	std::cin >> S;
	colours.assign(M, std::vector<int>());

	for (int i = 0; i < N; ++i) {
		int C;
		std::cin >> C, --C;

		colours[C].push_back(i);
	}

	for (std::vector<int> chars : colours) {
		char tmp = S[chars[chars.size() - 1]];

		for (int i = chars.size() - 1; i > 0; --i)
			S[chars[i]] = S[chars[i - 1]];
		S[chars[0]] = tmp;
	}

	std::cout << S << std::endl;

	return 0;
}
