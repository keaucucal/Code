#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

inline ll add(const ll &a, const ll &b) {
	return ((a + b) % mod + mod) % mod;
}

int main() {
	int n, a, b, k;
	cin >> n >> a >> b >> k;
	// start at a, you will never reach the opposite side of b
	
	if (a > b) {
		// size = n - b
		n -= b;
		// a = a - b / 1-based
		a -= b;
		b = 0;
	} else {
		// size = b - 1
		n = b - 1;
	}

	vector<ll> dp(n + 1);
	dp[a] = 1;

	for (int t = 0; t < k; t++) {
		vector<ll> temp(n + 2);
		for (int i = 1; i <= n; i++) {
			int d = abs(i - b) - 1;
			int l = max(1, i - d), r = min(n + 1, i + d + 1);

			temp[l] = add(temp[l], dp[i]);
			temp[r] = add(temp[r], -dp[i]);
			
			dp[i] *= -1;
		}

		for (int i = 1; i <= n; i++) {
			temp[i] = add(temp[i], temp[i - 1]);
			dp[i] = add(dp[i], temp[i]); 
		}
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = add(ans, dp[i]);
	}

	cout << ans << '\n';
}
