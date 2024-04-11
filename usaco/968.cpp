#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);

	int n, m;
	cin >> n >> m;

	vector<char> milk(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> milk[i];
	}

	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> component(n + 1);
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (component[i]) continue;
		cur++;
		component[i] = cur;

		// BFS
		queue<int> q;
		q.push(i);
		char type = milk[i];
		while (!q.empty()) {
			int s = q.front();
			q.pop();

			
			for (int u : adj[s]) {
				if (component[u]) continue;
				if (milk[u] == type) {
					component[u] = cur;
					q.push(u);
				}
			}
		}
	}

	while (m--) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		
		if (component[a] != component[b]) cout << 1;
		else cout << (milk[a] == c);
	}
}
