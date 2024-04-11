#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <climits>
using namespace std;
using ll = long long;

int n;
vector<pair<int, int>> v;

ll solve() {
    sort(v.begin(), v.end());
    vector<pair<int, int>> pre(n), suf(n);

    auto upd = [](const pair<int, int> &a, const int &b) -> pair<int, int> {
        return {min(a.first, b), max(a.second, b)};
    };

    // cnt pre & suf
    pre[0] = {v[0].second, v[0].second};
    for (int i = 1; i < n; i++) pre[i] = upd(pre[i - 1], v[i].second);

    suf[n - 1] = {v[n - 1].second, v[n - 1].second};
    for (int i = n - 2; i >= 0; i--) suf[i] = upd(suf[i + 1], v[i].second);

    ll total = (ll)(v[n - 1].first - v[0].first) * (pre[n - 1].second - pre[n - 1].first);
    ll save = LLONG_MAX;

    for (int i = 0; i < n - 1; i++) {
        if (v[i].first == v[i + 1].first) continue;

        ll first = (ll)(v[i].first - v[0].first) * (pre[i].second - pre[i].first);
        ll second = (ll)(v[n - 1].first - v[i + 1].first) * (suf[i + 1].second - suf[i + 1].first);

        save = min(save, first + second);
    }

    return total - save;
}

int main() {
    freopen("split.in", "r", stdin);
    freopen("split.out", "w", stdout);

    cin >> n;
    v.resize(n);
    for (auto &i : v) cin >> i.first >> i.second;

    ll ans = 0;
    ans = max(ans, solve());

    for (auto &i : v) swap(i.first, i.second);
    ans = max(ans, solve()); // y

    cout << ans << '\n';
}
