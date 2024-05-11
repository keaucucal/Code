#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;

void solve() {
	vector<int> v(N + 1), dp(N + 1);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> v[i];
	
	dp[0] = 0, dp[1] = v[1], dp[2] = v[2];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3]) + v[i];
	}

	cout << max(dp[n], dp[n - 1]) << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
