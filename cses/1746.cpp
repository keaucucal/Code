#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    if (v[0]) dp[0][v[0]] = 1;
    else fill(dp[0].begin(), dp[0].end(), 1);

    for (int i = 1; i < n; i++) {
        if (v[i]) {
            if (v[i] - 1 > 0) dp[i][v[i]] += dp[i - 1][v[i] - 1];
            dp[i][v[i]] += dp[i - 1][v[i]];
            if (v[i] + 1 <= m) dp[i][v[i]] += dp[i - 1][v[i] + 1];
            dp[i][v[i]] %= mod;
        } else {
            for (int j = 1; j <= m; j++) {
                if (j - 1 > 0) dp[i][j] += dp[i - 1][j - 1];
                dp[i][j] += dp[i - 1][j];
                if (j + 1 <= m) dp[i][j] += dp[i - 1][j + 1];
                dp[i][j] %= mod;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << '\n';

    return 0;
}
