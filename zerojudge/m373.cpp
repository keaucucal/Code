#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    vector<int> d(k + 1), p(k + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        p[0] = v[i] + (d[0] > 0 ? d[0] : 0);
        for (int j = 1; j <= k; j++) {
            p[j] = max(d[j - 1], d[j] + v[i]);
        }
        
        d.swap(p);
        ans = max(ans, d[k]);
    }

    cout << ans << '\n';
}
