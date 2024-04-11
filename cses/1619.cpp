#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> v;

    while (n--) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, 1});
        v.push_back({b, -1});
    }

    sort(v.begin(), v.end());

    int ans = 0;
    int sum = 0;
    for (const auto &x : v) {
        sum += x.second;
        ans = max(ans, sum);
    }

    cout << ans << '\n';
    return 0;
}
