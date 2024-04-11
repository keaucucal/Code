#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> visited(n + 1);
    vector<int> color(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;

        queue<int> q;
        q.push(i);
        color[i] = 1;
        while (!q.empty()) {
            int s = q.front(); q.pop();
            if (visited[s]) continue;
            visited[s] = true;
            
            for (auto u : adj[s]) {
                if (color[s] == color[u]) {
                    cout << "IMPOSSIBLE\n";
                    return 0;
                }

                color[u] = (color[s] == 1 ? 2 : 1);
                q.push(u);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << color[i] << ' ';
    } 
    cout << '\n';
}
