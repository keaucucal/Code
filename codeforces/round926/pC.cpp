#include <iostream>
using namespace std;

void solve() {
    int k, x, a;
    cin >> k >> x >> a;
    
    int ans = 1;
    for (int i = 0; i < x; i++) {
        int bet = ans / (k - 1) + 1;
        ans += bet;
        if (ans > a) break;
    }

    cout << (ans <= a ? "YES" : "NO") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
