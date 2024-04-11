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

    int a = v[n - 1], b = v[0];
    int c = v[n - 2], d = v[1];

    cout << (a - b) + (c - b) + (c - d) + (a - d) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
