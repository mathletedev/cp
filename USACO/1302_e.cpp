#include <iostream>
#include <tuple>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	std::cin >> t;

	while (t--) {
		int n, tc, tm;
		std::cin >> n >> tc >> tm;

		std::vector<std::tuple<long long, long long, long long>> orders(
		    n);

		for (int i = 0; i < n; ++i) {
			long long a, b, c;
			std::cin >> a >> b >> c;

			orders[i] = {a, b, c};
		}

		for (int s = 0; s <= tc + tm; ++s) {
			for (int i = 0; i <= s; ++i) {
				long long newTc = tc - i, newTm = tm - (s - i);
				if (newTc < 1 || newTm < 1)
					continue;

				for (int i = 0; i < n; ++i) {
					if (std::get<0>(orders[i]) * newTc +
						std::get<1>(orders[i]) * newTm >
					    std::get<2>(orders[i]))
						goto skip;
				}

				std::cout << s << std::endl;
				goto end;

			skip:;
			}
		}

	end:;
	}

	return 0;
}
