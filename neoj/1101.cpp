#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> color(n + 1); // 0 -> not visited
	for (int i = 1; i <= n; i++) {
		if (color[i]) continue;

		queue<int> q;
		q.push(i);
		color[i] = 1;
		while (!q.empty()) {
			int s = q.front();
			q.pop();

			for (int u : adj[s]) {
				if (color[u] == color[s]) {
					cout << "RAINBOW.\n";
					return;
				}
				
				if (color[u]) continue;
				color[u] = (color[s] == 1 ? 2 : 1);
			
				q.push(u);
			}
		}
	}

	cout << "NORMAL.\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
