#include <iostream>
#include <vector>
#include <climits>
using namespace std;
vector<int> dp(500);

void solve() {
    int n;
    cin >> n;

    
    if (n < 30) {
        cout << dp[n] << '\n';
    } else {
        int k = (n - 30) / 15 + 1;
        n -= k * 15;
        cout << k + dp[n] << '\n'; 
    }
}

int main() {
    vector<int> coins = {1, 3, 6, 10, 15};
    for (int i = 1; i < 500; i++) {
        dp[i] = INT_MAX;
        for (int c : coins) {
            if (i >= c)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
