#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[100005];
vector<bool> vis(100005);
int n, m;

void dfs(int s) {
    if (vis[s]) return;

    vis[s] = true;
    for (auto u : adj[s]) {
        dfs(u);
    } 
}

int main() {
    cin >> n >> m;

    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        ans.push_back(i);
        dfs(i);
    }
    
    cout << ans.size() << '\n';
    for (const int &i : ans) {
        cout << i - 1 << ' ' << i << '\n';
    }
}
