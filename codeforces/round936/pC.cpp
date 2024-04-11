#include <iostream>
#include <vector>
#include <functional>
using namespace std;
#define int long long

int bs(int l, int r, function<bool(int)> check) {
	while (l < r) {
		int mid = l + (r - l + 1) / 2;
		if (check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}

	return l;
}

void solve() {
	int n, k;
	cin >> n >> k;

	vector<vector<int>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}

	int component;
	function<int(int, int, int)> DFS;
	DFS = [&](int s, int p, int x) {
		int cnt = 1;
		for (int u : adj[s]) {
			if (u == p) continue;
			cnt += DFS(u, s, x);
		}
		if (cnt >= x) {
			cnt = 0;
			component++;
		}

		return cnt;
	};

	cout << bs(0, 1e5, [&](const int &x) {
			component = 0;
			DFS(1, 0, x);
			/*
			for (int i = n; i >= 1; i--) {
				if (tree[i] - cost >= x) {
					cnt++;
					cost += tree[i];
				}
			}
			*/

			return component > k;
		}) << '\n';
}

signed main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
