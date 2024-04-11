#include <iostream>
#include <map>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    m[0] = 1;

    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;

        sum += c - '0';
        ans += m[sum - i];
        m[sum - i]++;
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
