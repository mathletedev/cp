#include <iostream>
#include <stack>
#include <vector>

int N, P;

void solve() {
	std::cin >> N >> P;

	std::stack<char> A;
	std::stack<char> B;
	std::stack<char> C;

	for (int i = 0; i < N; ++i) {
		char x;
		std::cin >> x;

		if (A.empty() || A.top() != x) A.push(x);
	}

	for (int i = 0; i < N; ++i) {
		char x;
		std::cin >> x;

		if (B.empty() || B.top() != x) B.push(x);
	}

	int M = 0;
	bool phase1 = 1;
	char rem = '\0';
	std::vector<std::string> moves;
	while (A.size() + B.size() != 2 || !C.empty()) {
		++M;

		if (A.empty() || B.empty()) phase1 = 0;

		if (phase1 && A.top() == B.top()) {
			if (A.size() == 1 && B.size() == 1) {
				moves.push_back("2 1");
				moves.push_back("3 2");
				++M;
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
					moves.push_back("2 1");
				} else {
					A.pop();
					moves.push_back("1 2");
				}
				continue;
			}

			if (C.empty()) {
				if (A.size() > B.size()) {
					C.push(A.top());
					A.pop();
					moves.push_back("1 3");
				} else {
					C.push(B.top());
					B.pop();
					moves.push_back("2 3");
				}
				continue;
			}

			if (A.top() == C.top()) {
				A.pop();
				moves.push_back("1 3");
			} else {
				B.pop();
				moves.push_back("2 3");
			}
			continue;
		}

		if (rem == '\0') {
			if (A.empty()) {
				rem = 'B';
				A.push(B.top());
				B.pop();
				moves.push_back("2 1");
			} else {
				rem = 'A';
				B.push(A.top());
				A.pop();
				moves.push_back("1 2");
			}
			continue;
		}

		if (rem == 'A') {
			if (A.size() == 1) {
				C.pop();
				moves.push_back("3 1");
				continue;
			}
			if (!C.empty() && A.top() == C.top())
				moves.push_back("1 3");
			else
				moves.push_back("1 2");
			A.pop();
		} else {
			if (B.size() == 1) {
				C.pop();
				moves.push_back("3 2");
				continue;
			}
			if (!C.empty() && B.top() == C.top())
				moves.push_back("2 3");
			else
				moves.push_back("2 1");
			B.pop();
		}
	}

	std::cout << M << std::endl;
	if (P == 1) return;

	for (auto move : moves)
		std::cout << move << std::endl;
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
