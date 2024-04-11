#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define n 300

int main() {
    vector<int> dp(n);
    vector<int> coins = {1, 3, 4, 7};

    
    
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        dp[i] = INT_MAX;
        for (int c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    }
        int tmp = -12;
        for (int i = 0; i < n; i++) {
            cout << dp[i] - tmp << ' ';
            if (i % 84 == 0) {
                tmp += 12;
                cout << '\n';
            }
        }
}
