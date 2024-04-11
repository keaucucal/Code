#include <iostream>
#include <functional>
#include <cmath>
#include <climits>
#include <string>
using namespace std;
using ll = long long;

ll bs(ll l, ll r, function<bool(ll)> f) {
    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (f(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    return l;
}

int main() {
    ll x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll n;
    string s;
    cin >> n >> s;

    ll ans = bs(0, LLONG_MAX, [&](ll k) {
        ll x = 0, y = 0;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
            else if (s[i] == 'L') x--;
            else x++;
        }

        x = x1 + x * (k / n);
        y = y1 + y * (k / n);

        for (ll i = 0; i < k % n; i++) {
            if (s[i] == 'U') y++;
            else if (s[i] == 'D') y--;
            else if (s[i] == 'L') x--;
            else x++;
        }

        return (abs(x2 - x) + abs(y2 - y)) <= k;
    });
    cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
}
