#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> adj;
vector<long long> dp, ans;

void dfs1(int s, int e, int dist) {
    ans[1] += dist;
    dp[s] = 1;
    for (auto u : adj[s]) {
        if (u == e) continue;

        dfs1(u, s, dist + 1);
        dp[s] += dp[u];
    }
}

void dfs2(int s, int e) {
    for (auto u : adj[s]) {
        if (u == e) continue;

        ans[u] = ans[s] + n - 2 * dp[u];
        dfs2(u, s);
    }
}

int main() {
    cin >> n;
    adj.resize(n + 1);
    dp.resize(n + 1);
    ans.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(1, 0, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
