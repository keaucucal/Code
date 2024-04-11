#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> maxDist, secMax, path;

void dfs(int s, int e) {
    for (int u : adj[s]) {
        if (u == e) continue;

        dfs(u, s);
        if (maxDist[u] + 1 > maxDist[s]) {
            secMax[s] = maxDist[s];
            maxDist[s] = maxDist[u] + 1;
            path[s] = u;
        } else if (maxDist[u] + 1 > secMax[s]) {
            secMax[s] = maxDist[u] + 1;
        }
    }
}

void dfs2(int s, int e) {
    for (int u : adj[s]) {
        if (u == e) continue;

        if (path[s] == u) {
            if (secMax[s] + 1 > maxDist[u]) {
                secMax[u] = maxDist[u];
                maxDist[u] = secMax[s] + 1;
                path[u] = s;
            } else if (secMax[s] + 1 > secMax[u]) {
                secMax[u] = secMax[s] + 1;
            }
        } else {
            secMax[u] = maxDist[u];
            maxDist[u] = maxDist[s] + 1;
            path[u] = s;
        }
        
        dfs2(u, s);
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

    maxDist.resize(n + 1);
    secMax.resize(n + 1);
    path.resize(n + 1);

    dfs(1, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << maxDist[i] << ' ';
    }
    cout << '\n';
}
