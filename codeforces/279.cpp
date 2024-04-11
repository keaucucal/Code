#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    int l = 0, r = 0;
    int sum = 0, ans = 0;
    while (r < n) {
        sum += v[r];
        if (sum <= t) ans = max(ans, r - l + 1);
        else sum -= v[l], l++;

        r++;
    }

    cout << ans << '\n';
}
