#include <iostream>
#include <vector>
using namespace std;

#define int long long
const int mod = 2 * (1e9 + 7);

signed main() {
    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;

    if (sum & 1) {
        cout << 0 << '\n';
        return 0;
    }

    sum /= 2;
    vector<int> dp(sum + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= i; j--) {
            dp[j] += dp[j - i];
            dp[j] = dp[j] % mod;
        }
    }

    cout << dp[sum] / 2 << '\n';
}
