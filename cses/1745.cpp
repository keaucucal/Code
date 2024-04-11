#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;
    for (auto &i : v) {
        cin >> i;
        sum += i;
    }

    vector<bool> dp(sum + 1);
    dp[0] = true;
    for (const int &c : v) {
        for (int i = sum; i >= 0; i--) {
            if (dp[i]) dp[i + c] = true;
        }
    }

    vector<int> ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << '\n';
    for (const int &i : ans) cout << i << ' ';

    return 0;
}
