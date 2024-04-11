#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 1e7;

int main() {
    int n;
    cin >> n;
    
    vector<int> dp(n + 1);
    dp[0] = 0;
    for (int x = 1; x <= n; x++) {
        dp[x] = INF;
        int temp = x;
        while (temp) {
            dp[x] = min(dp[x], dp[x - temp % 10] + 1);
            temp /= 10;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
