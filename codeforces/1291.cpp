#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<vector<int>> dp(s.length() + 1, vector<int>(26));
    for (int i = 1; i <= s.length(); i++) {
        dp[i] = dp[i - 1];
        dp[i][s[i - 1] - 'a']++;
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        
        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (dp[r][i] - dp[l - 1][i]) cnt++;
        }

        if (l == r || s[l - 1] != s[r - 1] || cnt >= 3) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}
