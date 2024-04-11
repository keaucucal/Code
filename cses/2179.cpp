#include <iostream>
#include <vector>
#include <utility>
#include <functional>
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


	vector<int> vis(n + 1);
	int timer = 1;
	vector<bool> odd(n + 1);

	vector<pair<int, int>> ans;
	function<void(int, int)> DFS;
	DFS = [&](int s, int v) {
		vis[s] = timer++;
		for (int u : adj[s]) {
			if (u == v) continue;

			if (!vis[u]) {
				DFS(u, s);

				if (odd[u]) {
					ans.push_back({u, s});
					odd[u] = false;
				} else {
					ans.push_back({s, u});
					odd[s] = !odd[s];
				}
			} else if (vis[u] < vis[s]) {
				ans.push_back({u, s});
				odd[u] = !odd[u];
			}
		}
	};

	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		DFS(i, 0);
		if (odd[i]) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
	}

	for (pair<int, int> i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}
}
