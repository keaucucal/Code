#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; i++) cin >> books[i].first; // price
    for (int i = 0; i < n; i++) cin >> books[i].second; // pages

    vector<int> dp(x + 1);
    for (const auto &b : books) {
        for (int i = x; i >= 0; i--) {
            if (i - b.first >= 0) {
                dp[i] = max(dp[i], dp[i - b.first] + b.second);
            }
        }
    }

    cout << dp[x] << '\n';
    return 0;
}
