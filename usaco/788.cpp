#include <iostream>
#include <vector>
#include <utility>
#include <functional>
using namespace std;

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	vector<vector<pair<int, int>>> adj(n + 1);
	for (int i = 1; i < n; i++) {
		int a, b, r;
		cin >> a >> b >> r;
		adj[a].push_back({b, r});
		adj[b].push_back({a, r});
	}

	int k, v;
	function<int(int, int)> DFS;
	DFS = [&](int s, int p) -> int {
		int ret = 1;
		for (const auto &[u, r] : adj[s]) {
			if (u == p) continue;
	
			if (r >= k) {
				ret += DFS(u, s);
			}
		}

		return ret;
	};

	while (q--) {
		cin >> k >> v;
		// video v with least k relevance

		cout << DFS(v, 0) - 1 << '\n';
		// minus itself
	}
}
