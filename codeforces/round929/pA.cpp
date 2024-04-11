#include <iostream>
#include <cmath>
using namespace std;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    while (n--) {
        int a;
        cin >> a;
        sum += abs(a);
    }

    cout << sum << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
