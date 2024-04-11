#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    
    int ans = 0;
    for (int i = 1; i < n; i++) {
        ans += v[i] - v[i - 1];
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
