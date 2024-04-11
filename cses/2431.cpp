#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

ll pow(ll x, int y) {
    ll ans = 1;
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    
    return ans;
}

ll k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        cin >> k;
        int times = 1;
        ll x = 9;
        while (k - x > 0) {
            k -= x;
            times++;
            x = 9 * pow(10, times - 1) * times;
        }

        k--;
        ll ans = pow(10, times - 1) + k / times;

        string s = to_string(ans);
        cout << s[k % times] << '\n';
    }

    return 0;
}
