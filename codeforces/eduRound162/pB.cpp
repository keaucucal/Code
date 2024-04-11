#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<int> health(n);
    vector<int> v(n + 1);
    for (auto &i : health) cin >> i;
    for (const auto &i : health) {
        int x;
        cin >> x;
        if (x < 0) x *= -1;
        v[x] += i;
    }
    
    long long bullets = 0;
    for (int i = 1; i <= n; i++) {
        bullets += k - v[i];
        if (bullets < 0) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
