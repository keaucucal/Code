#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    int n = a.length();
    int m = b.length();

    int dp[n + 1][m + 1];
    dp[0][0] = 0;
    for (int j = 1; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        dp[i][0] = i;
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                            dp[i - 1][j - 1] + (a[i - 1] != b[j - 1]));
        }
    }

    cout << dp[n][m] << '\n';
    return 0;
}
