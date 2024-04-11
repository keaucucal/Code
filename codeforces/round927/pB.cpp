#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
   
    int ans; 
    cin >> ans;
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;

        ans = (ans / a + 1) * a;
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
