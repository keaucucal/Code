#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) cin >> v[i];

    vector<int> presum(n + 1, INT_MIN), sufsum(n + 2, INT_MIN);
    for (int i = 1; i <= n; i++) presum[i] = max(presum[i - 1], v[i] + i);
    for (int i = n; i >= 1; i--) sufsum[i] = max(sufsum[i + 1], v[i] - i);

    int ans = 0;
    for (int i = 2; i <= n - 1; i++) {
        ans = max(ans, presum[i - 1] + v[i] + sufsum[i + 1]);
    }

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
