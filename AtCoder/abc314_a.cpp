#include <iostream>

const std::string PI = "3."
		       "1415926535897932384626433832795028841971693993751058209"
		       "749445923078164062862089986280348253421170679";

int N;

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	std::cin >> N;

	std::cout << PI.substr(0, N + 2) << std::endl;

	return 0;
}
