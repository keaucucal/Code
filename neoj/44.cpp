#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void solve() {
	int n, m;
	cin >> n >> m;

	vector<string> v(n);
	for (string &s : v) cin >> s;
	
	vector<vector<bool>> vis(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != 'K') continue;

			queue<tuple<int, int, int>> q;
			q.push({i, j, 0});
			while (!q.empty()) {
				int x, y, dist;
				tie(x, y, dist) = q.front();
				q.pop();

				if (v[x][y] == '@') {
					cout << dist << '\n';
					return;
				}

				if (vis[x][y] || v[x][y] == '#') continue;
				vis[x][y] = true;

				for (int k = 0; k < 4; k++) {
					q.push({x + dx[k], y + dy[k], dist + 1});
				}
			}
		}
	}

	cout << "= =\"" << '\n';
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
