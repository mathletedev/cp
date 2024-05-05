#include <iostream>
#include <stack>

int N, P;

void solve() {
	std::cin >> N >> P;

	std::stack<char> A;
	std::stack<char> B;
	std::stack<char> C;

	char A1 = '\0';
	for (int i = 0; i < N; ++i) {
		char x;
		std::cin >> x;

		if (A.empty() || A.top() != x) A.push(x);

		if (A1 == '\0') A1 = x;
	}

	char B1 = '\0';
	for (int i = 0; i < N; ++i) {
		char x;
		std::cin >> x;

		if (B.empty() || B.top() != x) B.push(x);

		if (B1 == '\0') B1 = x;
	}

	int M = A.size() + B.size();
	if (A1 != B1) --M;
	if (M <= 2) --M;
	std::cout << M << std::endl;

	if (P == 1) return;

	bool phase1 = 1;
	char rem = '\0';
	for (int i = 0; i < M; ++i) {
		if (A.empty() || B.empty()) phase1 = 0;

		if (phase1 && A.top() == B.top()) {
			if (A.size() == 1 && B.size() == 1 && !C.empty()) {
				std::cout << "2 1" << std::endl;
				std::cout << "3 2" << std::endl;
				break;
			}
			if (A.size() == 1) {
				rem = 'B';
				phase1 = 0;
			} else if (B.size() == 1) {
				rem = 'A';
				phase1 = 0;
			}
		}

		if (phase1) {
			if (A.top() == B.top()) {
				if (A.size() > B.size()) {
					B.pop();
					std::cout << "2 1" << std::endl;
				} else {
					A.pop();
					std::cout << "1 2" << std::endl;
				}
				continue;
			}

			if (C.empty()) {
				if (A.size() > B.size()) {
					C.push(A.top());
					A.pop();
					std::cout << "1 3" << std::endl;
				} else {
					C.push(B.top());
					B.pop();
					std::cout << "2 3" << std::endl;
				}
				continue;
			}

			if (A.top() == C.top()) {
				A.pop();
				std::cout << "1 3" << std::endl;
			} else {
				B.pop();
				std::cout << "2 3" << std::endl;
			}
			continue;
		}

		if (rem == '\0') {
			if (A.empty()) {
				rem = 'B';
				A.push(B.top());
				B.pop();
				std::cout << "2 1" << std::endl;
			} else {
				rem = 'A';
				B.push(A.top());
				A.pop();
				std::cout << "1 2" << std::endl;
			}
			continue;
		}

		if (rem == 'A') {
			if (A.size() == 1) {
				std::cout << "3 1" << std::endl;
				continue;
			}
			if (!C.empty() && A.top() == C.top())
				std::cout << "1 3" << std::endl;
			else
				std::cout << "1 2" << std::endl;
			A.pop();
		} else {
			if (B.size() == 1) {
				std::cout << "3 2" << std::endl;
				continue;
			}
			if (!C.empty() && B.top() == C.top())
				std::cout << "2 3" << std::endl;
			else
				std::cout << "2 1" << std::endl;
			B.pop();
		}
	}
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
