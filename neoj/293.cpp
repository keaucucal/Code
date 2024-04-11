#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define sum first
#define sub second

vector<vector<int>> adj;
vector<pair<int, int>> tree;

void dfs(int s, int e) {
	for (auto u : adj[s]) {
		if (u == e) continue;
		dfs(u, s);
		tree[s].sum += tree[u].sum;
		tree[s].sub = max(tree[s].sub, tree[u].sum);
	}
}


void solve() {
	int n;
	cin >> n;

	adj.resize(n);
	tree.resize(n, {1, 0});
	
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0, -1);
	int mini = n, ind = 0;
	for (int i = 0; i < n; i++) {
		int tmp = max(tree[i].sub, n - tree[i].sum);
		if (tmp < mini) {
			ind = i;
			mini = tmp;
		}
	}
	
	cout << ind << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		adj.clear();
		tree.clear();
		solve();
	}
}
