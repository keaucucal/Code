#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &i : v) cin >> i;

    sort(v.begin(), v.end());

    ll ans = 0;
    for (int i = 0; i < n / 2; i++) {
        ans += v[i];
    }

    cout << ans << '\n';

    return 0;
}

