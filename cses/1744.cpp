#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int INF = INT_MAX;

int main() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, INF));

    for (int i = 0; i <= a; i++) {
        dp[0][i] = dp[i][0] = dp[i][i] = 0;
    }

    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
            }
        }
    }

    cout << dp[a][b] << '\n';
}
