#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_NUM = 1e9 * 1e3;

int n, m;
vector<int> t, d;

inline int calAns (const ll tar, vector<int> &s) {
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        while (s[i] >= tar) {
            ans += s[i];
            s[i] -= d[i];
        }
    }

    return ans;
}
// if the number is too high, return false
// if the number is too low or correct, return true
inline bool check(const ll tar, vector<int> s) {
    int cnt_set = 0;

    // cout << '\n' << tar << '\n';
    
    for (int i = 0; i < n; i++) {
        while (s[i] >= tar) {
            cnt_set++;

            if (cnt_set >= m) {
                return true;
            }
            s[i] -= d[i];
        }

        if (i < n - 1) cnt_set += t[i];
    }

    return false;
}

int main() {
    cin >> n >> m;
    vector<int> s(n);
    t.resize(n - 1);
    d.resize(n);
    for (auto &i : t) cin >> i;
    for (auto &i : s) cin >> i;
    for (auto &i : d) cin >> i;

    ll l = 0, r = MAX_NUM + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid, s)) l = mid;
        else r = mid;
        cout << l << ' ' << r << '\n';
    }

    cout << calAns(r, s) + calAns(l, s) << '\n';

    return 0;
}
