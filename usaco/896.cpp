#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
#define int long long

signed main() {
    freopen("mountains.in", "r", stdin);
    freopen("mountains.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n); // left bottom and right bottom
                                 // of the mountain
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[i].first = x - y;
        v[i].second = x + y;
    }

    sort(v.begin(), v.end(), [](const auto &a, const auto &b){
        if (a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    });

    int ans = 0, hidden = 0;
    for (int i = 0; i < n; i++) {
        if (v[i].second <= hidden) continue;

        hidden = v[i].second;
        ans++;
    }

    cout << ans << '\n';
}
