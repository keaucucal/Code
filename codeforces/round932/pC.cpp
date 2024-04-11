#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
using namespace std;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for (auto &i : v) cin >> i.first >> i.second;
    sort(v.begin(), v.end(), [&](auto &a, auto &b) {
            return a.second < b.second;
    });

    int ans = 0;
    for (int i = 0; i < n; i++) {
        priority_queue<int> pq;
        int sum = 0;
        for (int j = i; j < n; j++) {
            int bcost = v[j].second - v[i].second;
            pq.push(v[j].first);
            sum += v[j].first;

            while (!pq.empty() && sum + bcost > l) {
                sum -= pq.top();
                pq.pop();
            }

            ans = max(ans, (int)pq.size());
        }
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
