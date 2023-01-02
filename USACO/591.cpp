#include <cstdio>
#include <iostream>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);

	int iB, fB, iS, fS, iG, fG, iP, fP;
	std::cin >> iB >> fB >> iS >> fS >> iG >> fG >> iP >> fP;

	int dP = fP - iP;
	int dG = (fG + dP) - iG;
	int dS = (fS + dG) - iS;

	std::cout << dS << std::endl;
	std::cout << dG << std::endl;
	std::cout << dP << std::endl;

	return 0;
}
