#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n), a(m);
    for (int &x : v) cin >> x;
    for (int &x : a) cin >> x;
    
    sort(v.begin(), v.end());
    sort(a.begin(), a.end());

    int i = 0, j = 0;
    int ans = 0;
    while (i < n && j < m) {
        if (abs(v[i] - a[j]) <= k) {
            ans++;
            i++;
            j++;
        } else {
            if (v[i] - a[j] > k) j++;
            else i++;
        }
    }

    cout << ans << '\n';

    return 0;
}
