#include <iostream>
using namespace std;

using ll = long long;
const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        ll x, y;
        cin >> x >> y;

        ll ans = 1;
        while (y) {
            if (y & 1) ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
