#include <iostream>
#include <vector>
using namespace std;
#define int long long

const int N = 100;
const int mod = 1000007;
vector<vector<int>> ncr(N + 1, vector<int>(N + 1));

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (auto &a : v) cin >> a;

	vector<int> dp(m + 1);
	for (int i = 1; i <= m; i++) {
		dp[i] = 1;
		for (const auto &a : v) {
			dp[i] = dp[i] * ncr[i][a] % mod;
		}

		for (int j = 1; j < i; j++) {
			dp[i] = (dp[i] - dp[i - j] * ncr[i][j] + mod) % mod;
		}
	}

	cout << dp[m] << '\n';
}

signed main() {
	for (int i = 0; i <= N; i++) {
		ncr[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % mod;
		}
	}

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
