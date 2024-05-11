#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
const int mod = 1e6 + 7;

int main() {
	int dp[N + 1][3][3]; // 0 = red, 1 = green, 2 = blue
	dp[1][0][0] = dp[1][1][1] = dp[1][2][2] = 1;
	dp[2][0][0] = dp[2][1][1] = dp[2][2][2] = 1;
	dp[2][0][1] = dp[2][1][0] = dp[2][0][2] = dp[2][2][0] = 1;
	dp[2][1][2] = dp[2][2][1] = 0;

	for (int i = 3; i <= N; i++) {
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % mod;
		dp[i][0][1] = (dp[i - 1][0][0] + dp[i - 1][0][1]) % mod;
		dp[i][0][2] = (dp[i - 1][0][0] + dp[i - 1][0][2]) % mod;
		
		dp[i][1][0] = (dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % mod;
		dp[i][1][1] = (dp[i - 1][1][0] + dp[i - 1][1][1]) % mod;
		dp[i][1][2] = (dp[i - 1][1][0] + dp[i - 1][1][2]) % mod;

		dp[i][2][0] = (dp[i - 1][2][0] + dp[i - 1][2][1] + dp[i - 1][2][2]) % mod;
		dp[i][2][1] = (dp[i - 1][2][0] + dp[i - 1][2][1]) % mod;
		dp[i][2][2] = (dp[i - 1][2][0] + dp[i - 1][2][2]) % mod;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][2][0] + dp[n][2][2]) % mod << '\n';
	}
}
