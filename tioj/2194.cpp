// tioj 2194.B.掃地機器人
// binary search
#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_NUM = 1e9;
int n, m;
vector<int> t, s, d;

int e;
inline bool check(const ll x) {
    int cnt = 0;
    for (int i = 0; i <= e; i++) {
        if (s[i] < x) continue;
        if (d[i] == 0) return true;

        cnt += (s[i] - x) / d[i] + 1;
    }

    return m <= cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    t.resize(n - 1);
    s.resize(n);
    d.resize(n);
    for (auto &x : t) cin >> x;
    t.push_back(0);
    for (auto &x : s) cin >> x;
    for (auto &x : d) cin >> x;

    ll ans = 0;
    for (e = 0; e < n; e++) {
        ll l = 0, r = MAX_NUM;
        while (l + 1 < r) {
            ll mid = (l + r) / 2;
            if (check(mid)) l = mid;
            else r = mid;

        }

        int a = 0;
        ll sum = 0;
        for (int i = 0; i <= e; i++) {
            if (s[i] <= l) continue;
            if (d[i] == 0) continue;

            ll height = (s[i] - l) / d[i] + 1;
            if (s[i] % d[i] == l % d[i]) height--;
            ll bottom = s[i] - d[i] * (height - 1);
            sum += (s[i] + bottom) * height / 2;
            
            a += height;
        }
        sum += l * (m - a);

        ans = sum > ans ? sum : ans;

        m -= t[e];
    }

    cout << ans << '\n';

    return 0;
}
