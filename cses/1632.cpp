#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    for (auto &i : v) cin >> i.second >> i.first;
    sort(v.begin(), v.end());

    multiset<int, greater<int>> ms;
    while (k--) ms.insert(0);

    int ans = 0;
    for (const auto &i : v) {
        auto it = ms.lower_bound(i.second);
        if (it == ms.end()) continue;

        ms.erase(it);
        ms.insert(i.first);
        ans++;
    }
    
    cout << ans << '\n';
}
