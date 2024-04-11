#include <iostream>
#include <cmath>
#include <set>
using namespace std;

void solve() {
    int a, b, l;
    cin >> a >> b >> l;
    
    set<int> ans;
    int x = 1;
    while (l % x == 0) {
        int y = 1;
        while (l / x % y == 0) {
            ans.insert(l / x / y);
            y *= b;
        }
        x *= a;
    }

    cout << ans.size() << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
