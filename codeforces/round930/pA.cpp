#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int i = 1;
    while ((1 << i) <= n) i++;

    cout << (1 << (i - 1)) << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
