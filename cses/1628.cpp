#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    vector<ll> v(n);
    for (auto &i : v) cin >> i;

    auto get_divide = [&](int l, int r) -> vector<ll> {
        int len = r - l + 1;
        vector<ll> ret;
        ret.reserve(len);

        for (int i = 0; i < (1 << len); i++) {
            ll sum = 0;
            for (int j = 0; j < len; j++) {
                if (i & (1 << j)) sum += v[l + j];
            }
            ret.push_back(sum);
        }
        return ret;
    };

    vector<ll> left = get_divide(0, n / 2 - 1);
    vector<ll> right = get_divide(n / 2, n - 1);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    
    ll ans = 0;
    for (const auto &i : left) {
        ans += upper_bound(right.begin(), right.end(), x - i) - lower_bound(right.begin(), right.end(), x - i);
    }

    cout << ans << '\n';
}
