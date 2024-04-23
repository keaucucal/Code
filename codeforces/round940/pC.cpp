#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 3e5;
const int mod = 1e9 + 7;
vector<int> dp(N + 5);

void solve() {
	int n, k;
	cin >> n >> k;

	while (k--) {
		int x, y;
		cin >> x >> y;
		if (x == y) n--;
		else n -= 2;
	}

	cout << dp[n] << '\n';
}

signed main() {
	dp[1] = 1;
	dp[2] = 3;
	int temp = 2;
	for (int i = 3; i <= N; i++) {
		dp[i] = (dp[i - 1] + temp) % mod;
		temp = (temp + 2 * dp[i - 1]) % mod;
	}

	cout << dp[3] << '\n';
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
