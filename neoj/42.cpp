#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> v(n + 2, vector<bool>(m + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			v[i][j] = (c == '.');
		}
	}

	vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (vis[i][j] || v[i][j] == false) continue;

			ans++;
			queue<pair<int, int>> q;
			q.push({i, j});
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				if (vis[x][y] || v[x][y] == false) continue;
				vis[x][y] = true;

				for (int k = 0; k < 4; k++) {
					q.push({x + dx[k], y + dy[k]});
				}
			}
		}
	}

	cout << ans << '\n';
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
