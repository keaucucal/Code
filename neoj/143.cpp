#include <iostream>
#include <vector>
using namespace std;

const int INF = INT32_MAX;

void solve() {
	int n;
	cin >> n;

	vector<int> pre(n + 1);
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
	for (int i = 1; i <= n; i++) {
		int a;
		cin >> a;
		pre[i] = pre[i - 1] + a;
		dp[i][i] = 0;
	}

	for (int len = 2; len <= n; len++) {
		for (int l = 1, r = len; r <= n; l++, r++) {
			for (int k = l; k < r; k++) {
				dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + pre[r] - pre[l - 1]);
			}
		}
	}

	cout << dp[1][n] << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
