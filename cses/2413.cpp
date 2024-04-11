#include <iostream>
using namespace std;
typedef long long ll;

const int MAX_NUM = 1e6;
const int mod = 1e9 + 7;
ll dp[MAX_NUM + 2][2];

int main() {
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= MAX_NUM; i++) {
        dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 4) % mod;
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
    }

    return 0;
}
