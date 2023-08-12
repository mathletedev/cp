#include <iostream>
#include <vector>

const int MAX_A = 5e6;

int N;
std::vector<bool> sieve(MAX_A, 1);
std::vector<int> last_prime(4);
std::vector<int> num_turns(MAX_A);

void solve() {
	std::cin >> N;

	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		int a;
		std::cin >> a;

		if (num_turns[a] / 2 < ans / 2)
			ans = num_turns[a];
	}

	std::cout << "Farmer " << (ans % 2 ? "John" : "Nhoj") << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);

	last_prime[0] = 2;
	last_prime[1] = 1;
	num_turns[0] = 0;
	num_turns[1] = 1;
	for (int i = 2; i < MAX_A; ++i) {
		if (sieve[i]) {
			for (int j = i; j < MAX_A; j += i)
				sieve[j] = 0;

			last_prime[i % 4] = i;
		}

		num_turns[i] = (i - last_prime[i % 4]) / 2 + 1;
	}

	int T;
	std::cin >> T;

	while (T--)
		solve();

	return 0;
}
