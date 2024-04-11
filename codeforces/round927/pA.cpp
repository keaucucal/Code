#include <iostream>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '*' && s[i] == '*') break;
        if (s[i] == '@') ans++;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
