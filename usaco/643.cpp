#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    sort(v.begin(), v.end());

    vector<int> take(n);
    int r = 0;
    for (int l = 0; l < n; l++) {
        while (r < n && v[r] - v[l] <= k) r++;
        take[l] = r - l;
    }

    vector<int> suf(n + 1);
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = max(suf[i + 1], take[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, take[i] + suf[i + take[i]]);
    }

    cout << ans << '\n';
}
