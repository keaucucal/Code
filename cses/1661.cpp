#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto &i : v) cin >> i;

    ll sum = 0;
    ll ans = 0;
    unordered_map<ll, int> m;
    m[0] = 1;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        ans += m[sum - x];
        m[sum]++;
    }

    cout << ans << '\n';
    return 0;
}
