#include <iostream>
#include <vector>
using namespace std;

#define int long long

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> presum(n + 1), precnt(n + 1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        presum[i] = presum[i - 1] + c;
        precnt[i] = precnt[i - 1] + (c == 1);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--;
        
        int sum = presum[r] - presum[l];
        int cnt = precnt[r] - precnt[l];

        if (sum < r - l + cnt || l + 1 == r) cout << "NO\n";
        else cout << "YES\n";
    }
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
