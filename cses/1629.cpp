#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    while (n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({b, a});
    }
    sort(v.begin(), v.end());

    int pre = 0;
    int ans = 0;
    for (const auto &x : v) {
        if (x.second < pre) continue;

        ans++;
        pre = x.first;
    }

    cout << ans << '\n';
    return 0;
}
