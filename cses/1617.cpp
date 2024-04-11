#include <iostream>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    ll x = 2;
    ll ans = 1;
    while (n) {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }

    cout << ans << '\n';
    return 0;
}
