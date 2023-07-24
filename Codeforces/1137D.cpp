#include <iostream>

int read() {
	int k;
	std::cin >> k;

	for (int i = 0; i < k; ++i) {
		int _;
		std::cin >> _;
	}

	return k;
}

void query(std::string query) {
	std::cout << "next " << query << std::endl;
	std::cout.flush();
}

void floyd1() {
	query("0 1");
	read();

	query("0");
	int k = read();

	if (k == 3)
		return floyd1();
}

void floyd2() {
	query("0 1 2 3 4 5 6 7 8 9");
	int k = read();

	if (k == 2)
		return floyd2();

	std::cout << "done" << std::endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	floyd1();
	floyd2();

	return 0;
}
