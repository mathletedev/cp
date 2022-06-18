#include <algorithm>
#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		char s[n];
		std::cin >> s;
		int k;
		std::cin >> k;
		bool c[26];
		for (int i = 0; i < 26; i++)
			c[i] = false;
		for (int i = 0; i < k; i++) {
			char x;
			std::cin >> x;
			c[x - 'a'] = true;
		}
		int b = 0, l = 0;
		for (int i = 0; i < n; i++) {
			if (c[s[i] - 'a']) {
				b = std::max(b, i - l);
				l = i;
			}
		}
		std::cout << b << std::endl;
	}
	return 0;
}
