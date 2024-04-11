#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<int> distance(n + 1);
    vector<int> pre(n + 1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    visited[1] = true;
    queue<int> q;
    q.push(1);
    distance[1] = 1;
    while (!q.empty()) {
        int s = q.front(); q.pop();
        if (s == n) {
            cout << distance[n] << '\n';

            vector<int> ans;
            int a = n;
            while (a != 1) {
                ans.push_back(a);
                a = pre[a];
            }
            ans.push_back(1);
            reverse(ans.begin(), ans.end());

            for (auto i : ans) cout << i << ' ';
            cout << '\n';
            return 0;
        }

        for (auto u : adj[s]) {
            if (visited[u]) continue;
            visited[u] = true;

            distance[u] = distance[s] + 1;
            pre[u] = s;

            q.push(u);
        }
    }

    cout << "IMPOSSIBLE\n";
}
