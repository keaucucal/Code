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

    bool flag = true;
    if (v[0] == v[1]) flag = false;
    
    if (!flag) {
        for (int i = 2; i < n; i++) {
            if (v[i] % v[0]) flag = true;
        }
    }

    cout << (flag ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
