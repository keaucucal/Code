#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
int endnode;
int maxDist;

void dfs(int s, int e, int dist) {
    if (dist > maxDist) {
        maxDist = dist;
        endnode = s;
    }

    for (int u : adj[s]) {
        if (u != e) dfs(u, s, dist + 1);
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    maxDist = -1;
    dfs(1, 0, 0);
    maxDist = -1;
    dfs(endnode, 0, 0);

    cout << maxDist << '\n';
}
