#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> m;
    set<int> s;
    while (n--) {
        int l, r;
        cin >> l >> r;
        m[l].push_back(r);
        s.insert(l);
    }

    int i = *s.begin();
    s.insert(INF);

    priority_queue<int, vector<int>, greater<int>> pq;
    bool flag = true;
    while (i <= 1e9) {
        for (auto u : m[i]) pq.push(u);

        pq.pop();
        if (pq.empty()) i = *s.lower_bound(i + 1);
        else {
            if (pq.top() <= i) {
                flag = false;
                break;
            }
            i++;
        } 
    }

    cout << (flag ? "Yes" : "No") << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
