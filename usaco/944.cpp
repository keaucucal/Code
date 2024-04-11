#include <iostream>
#include <vector>
#include <utility>
using namespace std;
#define x first
#define y second

vector<vector<int>> adj;
vector<pair<int, int>> pos;
vector<bool> visited;
pair<int, int> lower_left, upper_right;

void dfs(int s) {
	if (visited[s]) return;
	visited[s] = true;

	lower_left.x = min(lower_left.x, pos[s].x);
	lower_left.y = min(lower_left.y, pos[s].y);
	upper_right.x = max(upper_right.x, pos[s].x);
	upper_right.y = max(upper_right.y, pos[s].y);

	for (auto u : adj[s]) {
		dfs(u);
	}
}

int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	// 0-based
	pos.resize(n);
	for (auto &i : pos) cin >> i.x >> i.y;

	adj.resize(n);
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	visited.resize(n);
	int ans = 1e9;
	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;
		lower_left = {1e9, 1e9}, upper_right = {0, 0};
		dfs(i);
		
		if (lower_left == upper_right) continue;	
		int fence = upper_right.x - lower_left.x + upper_right.y - lower_left.y;
		fence *= (lower_left.x == upper_right.x || lower_left.y == upper_right.y ? 1 : 2);

		ans = min(ans, fence);
	}

	cout << ans << '\n';
}
