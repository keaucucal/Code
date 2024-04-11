#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int main() {
    freopen("snowboots.in", "r", stdin);
    freopen("snowboots.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    
    multiset<pair<int, int>> snow; // first -> depth / second -> index
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i && i != n - 1) snow.insert({x, i});
    }

    priority_queue<tuple<int, int, int>> boots;
    for (int i = 0; i < m; i++) {
        int s, d;
        cin >> s >> d;
        boots.push({-s, d, i});
    }
    
    set<int> ground;
    ground.insert(0), ground.insert(n - 1);
    multiset<int> dist;
    dist.insert(n - 1);

    vector<int> ans(m);
    while (!boots.empty()) {
        int s, d, i;
        tie(s, d, i) = boots.top();
        s *= -1;
        boots.pop();

        while (!snow.empty()) {
            auto cur = *snow.begin();
            if (cur.first > s) break;

            int j = cur.second;
            auto it = ground.lower_bound(j);
            it--;
            auto it2 = ground.lower_bound(j);
            ground.insert(j);

            dist.erase(dist.find(*it2 - *it));
            dist.insert(j - *it);
            dist.insert(*it2 - j);


            snow.erase(snow.begin());
        }

        ans[i] = (d >= *dist.rbegin());
    }

    for (auto &i : ans) cout << i << '\n';
}
