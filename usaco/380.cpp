#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include <utility>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int bs(int l, int r, function<bool(int)> check) {
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	return l;
}

int main() {
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}

	int check = 0;
	pair<int, int> start;
	vector<vector<bool>> waypoint(n, vector<bool>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			waypoint[i][j] = a;
			check += a;
			if (a) {
				start = {i, j};
			}
		}
	}


	cout << bs(0, 1e9, [&](int k) {
			vector<vector<bool>> vis(n, vector<bool>(m));
			
			// BFS
			queue<pair<int, int>> q;
			q.push(start);
			vis[start.first][start.second] = true;

			int cnt = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				if (waypoint[x][y]) cnt++;

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i], ny = y + dy[i];
					// out of the border or visited
					if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny]) continue;
					// can't go through
					if (abs(v[x][y] - v[nx][ny]) > k) continue;

					q.push({nx, ny});
					vis[nx][ny] = true;
				}
			}

			return cnt == check;
		}) << '\n';
}
