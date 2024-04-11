#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

#define cow pair<int, pair<int, int>>
#define seniority first
#define arrive second.first
#define time second.second

int main() {
    freopen("convention2.in", "r", stdin);
    freopen("convention2.out", "w", stdout);

    int n;
    cin >> n;
    vector<cow> v;
    v.reserve(n + 1);
    for (int i = n; i > 0; i--) {
        int a, t;
        cin >> a >> t;
        v.push_back({i, {a, t}});
    }

    sort(v.begin(), v.end(), [](const cow &a, const cow &b) {
        if (a.arrive == b.arrive) return a.seniority > b.seniority;
        return a.arrive < b.arrive;
    });

    v.push_back({0, {INT_MAX, 0}});

    priority_queue<cow> q;
    int finish = 0, ans = 0;

    for (int i = 0; i <= n; i++) {
        cow c = v[i];

        if (c.arrive > finish) {
            if (q.empty()) finish = c.arrive + c.time;
            else {
                cow x = q.top();
                q.pop();
                ans = max(ans, finish - x.arrive);
                finish += x.time;
                i--;
            }
        } else {
            q.push(c);
        }
    }

    cout << ans << '\n';
}
