#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);

	int n;
	std::string a, b;
	std::cin >> n >> a >> b;

	int count = 0;
	bool wrong = false;
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i] && !wrong) {
			++count;
			wrong = true;
		} else if (a[i] == b[i] && wrong)
			wrong = false;
	}

	std::cout << count << std::endl;

	return 0;
}
