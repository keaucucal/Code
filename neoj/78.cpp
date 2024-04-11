#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int T;
    cin >> T;
    while (T--) {
        ll a, b, c, d, e;
        ll ans;
        cin >> a >> b >> c >> d >> e >> ans;

        ans += d + e;
        a -= 11 * e;
        b -= 5 * d;

        ans += (c / 4);

        ans++;
        switch (c % 4) {
            case 1:
                a -= 7;
                b -= 5;
                break;
            case 2:
                a -= 6;
                b -= 3;
                break;
            case 3:
                a -= 5;
                b -= 1;
                break;
            default:
                ans--;
        }

        if (b > 0) {
            ans += b / 9;
            if (b % 9) {
                ans++;
                a -= (36 - b % 9 * 4);
            }
        } else a -= b * -4;  

        if (a > 0) {
            ans += a / 36;
            if (a % 36) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
