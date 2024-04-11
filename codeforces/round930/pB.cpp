#include <iostream>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    
    string ans;
    ans += a[0];

    int change = n - 1;
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (flag) {
            ans += b[i];
        } else {
            if (a[i + 1] == '1' && b[i] == '0') {
                change = i;
                flag = true;
                ans += '0';
            } else {
                ans += a[i + 1];
            }
        }
    }

    ans += b[n - 1];

    int cnt = 1;
    for (int i = change; i > 0; i--) {
        if (b[i - 1] == a[i]) cnt++;
        else break;
    }

    cout << ans << '\n' << cnt << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
