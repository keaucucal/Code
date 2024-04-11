#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_NUM = 2e9;

ll n, k;
vector<int> v;

inline bool check(const ll C) {
    ll cnt = 0;

    int l = 0, r = n - 1;
    while(l <= r) {
        if(v[l] + v[r] >= C) cnt += (r - l + 1), r--;
        else l++;
    }

    return cnt >= k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    v.resize(n);
    for (auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    
    ll l = MAX_NUM * -1, r = MAX_NUM + 1;
    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }

    if(l & 1) cout << l << "\n2\n";
    else cout << l / 2 << "\n1\n";
    
    return 0;
}
