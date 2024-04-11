#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int ans(int l, int r, function<bool(int)> f) {
    l--;
    while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (f(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    
    return l;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    cout << ans(1, 2e9, [&](int x) {
        long long cnt = 0;
        for (int i = (n - 1) / 2; i < n; i++) {
            cnt += max(0, x - v[i]);
        }
        return cnt <= k;
    }) << '\n';
}
