#include <iostream>
#include <map>

using ll = long long;

void solve() {
	ll n, m;
	std::cin >> n >> m;

	std::map<ll, ll> v;
	for (int i = 0; i < n; ++i) {
		int a;
		std::cin >> a;
		++v[a];
	}

	ll ans = 0;

	for (const auto &pair : v) {
		ll k1 = pair.first, v1 = pair.second;
		ll k2 = k1 + 1, v2 = 0;
		if (v.find(k2) != v.end()) {
			v2 = v[k2];
		}

		for (ll i = 0; i <= v1; ++i) {
			ll first = i * k1;
			if (first > m) {
				continue;
			}

			ll rem = m - first;
			ll second = std::min<ll>(v2 * k2, rem / k2 * k2);

			ans = std::max(ans, first + second);
		}
	}

	std::cout << ans << std::endl;
}

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(nullptr);

	int t;
	std::cin >> t;

	while (t--) {
		solve();
	}

	return 0;
}
