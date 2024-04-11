#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);

    int n, q;
    cin >> n >> q;

    vector<int> v(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());

    while (q--) {
        int a, b;
        cin >> a >> b;
        
        auto r = upper_bound(v.begin(), v.end(), b);
        auto l = lower_bound(v.begin(), v.end(), a);
        // [l, r)

        cout << r - l << '\n';
    }
}
