#include <iostream>
#include <vector>
using namespace std;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> weight(n), value(n);
	for (int i = 0; i < n; i++) {
		cin >> weight[i] >> value[i];
	}

	vector<vector<int>> dp(m + 1, vector<int>(k + 1));
	for (int i = 0; i < n; i++) {
		for (int j = m; j >= weight[i]; j--) {
			for (int l = 1; l <= k; l++) {
				dp[j][l] = max(dp[j][l], dp[j - weight[i]][l - 1] + value[i]);
			}
		}
	}

	cout << dp[m][k] << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
