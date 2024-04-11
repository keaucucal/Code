#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &i : v) cin >> i;

    int l = 0;
    while (l < n && v[l] == 0) l++;
    int r = n - 1;
    while (r >= 0 && v[r] == 0) r--;
    
    if (r <= l) {
        cout << "0\n";
        return;
    }

    int ans = 0;
    for (int i = l; i <= r; i++) {
        if (v[i] == 0) ans++;
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
