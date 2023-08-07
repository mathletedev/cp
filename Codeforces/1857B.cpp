#include <iostream>

std::string X;

void solve() {
	std::cin >> X;

	int pos_4 = -1;
	for (int i = 0; i < X.size(); ++i) {
		if (X[i] >= '5') {
			if (i == 0)
				std::cout << "1" << std::string(X.size(), '0')
					  << std::endl;
			else if (pos_4 == -1)
				std::cout << X.substr(0, i - 1)
					  << (char)(X[i - 1] + 1)
					  << std::string(X.size() - i, '0')
					  << std::endl;
			else {
				if (pos_4 == 0)
					std::cout << "1"
						  << std::string(X.size(), '0')
						  << std::endl;
				else
					std::cout << X.substr(0, pos_4 - 1)
						  << (char)(X[pos_4 - 1] + 1)
						  << std::string(
							 X.size() - pos_4, '0')
						  << std::endl;
			}

			return;
		}

		if (X[i] == '4' && pos_4 == -1)
			pos_4 = i;
		else if (X[i] != '4')
			pos_4 = -1;
	}

	std::cout << X << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
