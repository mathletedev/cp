#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	std::string cows;
	std::cin >> cows;

	int gi = -1, hi = -1, gf, hf;
	for (int i = 0; i < n; ++i) {
		if (cows[i] == 'G') {
			if (gi == -1)
				gi = i;
			gf = i;
		} else {
			if (hi == -1)
				hi = i;
			hf = i;
		}
	}

	std::vector<int> e(n);
	for (int i = 0; i < n; ++i)
		std::cin >> e[i];

	int gl = -1, hl = -1;
	if (e[gi] > gf)
		gl = gi;
	if (e[hi] > hf)
		hl = hi;

	int count = 0;

	if (gl != -1 && hl != -1) {
		if (gl < hl && e[gl] <= hl)
			++count;
		else if (hl < gl && e[hl] <= gl)
			++count;
	}

	for (int i = 0; i < gl; ++i) {
		if (cows[i] == 'H' && e[i] > gl)
			++count;
	}
	for (int i = 0; i < hl; ++i) {
		if (cows[i] == 'G' && e[i] > hl)
			++count;
	}

	std::cout << count << std::endl;

	return 0;
}
