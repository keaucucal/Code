#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> cnt;

void dfs(int s) {
    cnt[s] = 1;
    for (auto u : adj[s]) {
        dfs(u);
        cnt[s] += cnt[u]; 
    }
}

int main() {
    int n;
    cin >> n;
    adj.resize(n + 1);
    cnt.resize(n + 1);

    for (int i = 2; i <= n; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= n; i++) {
        cout << cnt[i] - 1 << ' ';
    }   
    cout << '\n';
}
