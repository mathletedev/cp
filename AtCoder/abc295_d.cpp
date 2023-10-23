#include <iostream>
#include <map>

std::string S;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> S;

	int state = 0;
	std::map<int, long long> states;
	++states[state];

	for (char c : S) {
		state ^= 1 << (c - '0');

		++states[state];
	}

	long long ans = 0;
	for (auto x : states)
		ans += x.second * (x.second - 1) / 2;

	std::cout << ans << std::endl;

	return 0;
}
