#include <iostream>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k <= 4 * n - 4) {
        cout << (k + 1) / 2 << '\n';
    } else {
        cout << 2 * n - (4 * n - 2 - k) << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
