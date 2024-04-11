#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, bool>>> adj(n + 1);
	while (m--) {
		char c;
		int a, b;
		cin >> c >> a >> b;

		bool type = (c == 'S');
		adj[a].push_back({b, type});
		adj[b].push_back({a, type});
	}

	int ans = 0;
	vector<int> color(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (color[i] != -1) continue; // visited
		ans++;
	
		queue<pair<int, bool>> q;
		q.push({i, true});

		while (!q.empty()) {
			pair<int, bool> s = q.front();
			q.pop();

			color[s.first] = s.second;
			for (pair<int, bool> u : adj[s.first]) {
				bool type = u.second ? s.second : !s.second;
				// true -> same / false -> diff

				if (color[u.first] == -1) {
					q.push({u.first, type});
				} else if (color[u.first] != type) {
					cout << "0\n";
					return 0;
				}
			}
		}
	}

	cout << 1;
	while (ans--) cout << 0;
	cout << '\n';
}
