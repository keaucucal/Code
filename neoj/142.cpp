#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	
	for (int i = 0; i <= k; i++) {
		dp[i] = v[i];
	}

	for (int i = k + 1; i <= n; i++) {
		int res = 0;
		for (int j = max(i - k * 2 + 1, 0); j <= i - k; j++) {
			res = max(res, dp[j]);
		}

		dp[i] = res + v[i];
	}

	int ans = 0;
	for (int i = n - k + 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	
	cout << ans << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
