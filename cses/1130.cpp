#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<bool> used;
int ans = 0;

void dfs(int s, int e) {
    for (auto u : adj[s]) {
        if (u == e) continue;

        dfs(u, s);
        if (!used[u] && !used[s]) {
            used[u] = used[s] = true;
            ans++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    used.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0);
    cout << ans << '\n';
}
