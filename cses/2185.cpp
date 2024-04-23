#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> v(k);
	for (auto &a : v) cin >> a;

	ll ans = 0;
	for (int i = 1; i < (1 << k); i++) {
		ll pro = 1;
		for (int j = 0; j < k; j++) {
			if (i & (1 << j)) { // take
				if (pro > n / v[j]) {
					pro = n + 1;
					break;
				}

				pro *= v[j];
			}
		}

		if (__builtin_popcount(i) & 1) {
			ans += n / pro;
		} else {
			ans -= n / pro;
		}
	}

	cout << ans << '\n';
}
