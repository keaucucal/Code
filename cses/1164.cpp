#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int>> v(n); // arrive / departure / tag
    for (int i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i;
    }
    sort(v.begin(), v.end());

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // departure / room
    int cnt = 1;
    pq.push({v[0].first.second, cnt});

    vector<int> ans(n);
    ans[v[0].second] = cnt;
    for (int i = 1; i < n; i++) {
        auto cos = pq.top(); // departure / room
        int arr = v[i].first.first, dep = v[i].first.second, tag = v[i].second;

        if (cos.first >= arr) { // new room
            pq.push({dep, ++cnt});
            ans[tag] = cnt;
        } else { // room availible
            pq.pop();
            pq.push({dep, cos.second});
            ans[tag] = cos.second;
        }
    }

    cout << cnt << '\n';
    for (auto i : ans) cout << i << ' ';
}
