#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj, adj2;
vector<int> visited;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (int u : adj[s]) {
		dfs(u);
	}
}

void dfs2(int s) {
	if (visited[s]) return;
	visited[s] = true;
	for (int u : adj2[s]) {
		dfs2(u);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	adj.resize(n + 1);
	adj2.resize(n + 1);
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj2[b].push_back(a);
	}

	visited.assign(n + 1, false);
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << "NO\n";
			cout << 1 << ' ' << i << '\n';
			return 0;
		}
	}

	visited.assign(n + 1, false);
	dfs2(1);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cout << "NO\n";
			cout << i << ' ' << 1 << '\n';
			return 0;
		}
	}

	cout << "YES\n";
}
