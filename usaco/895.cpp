#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);
	
	int n;
	cin >> n;
	vector<vector<bool>> v(n + 2, vector<bool>(n + 2));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c;
			cin >> c;
			v[i][j] = (c == '#');
		}
	}

	int ans = 0, ans2 = 0;
	vector<vector<bool>> vis(n + 2, vector<bool>(n + 2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j] || !v[i][j]) continue;

			// BFS
			queue<pair<int, int>> q;
			q.push({i, j});
			vis[i][j] = true;

			int area = 0, perimeter = 0;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();

				area++;

				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k], ny = y + dy[k];
					if (vis[nx][ny]) continue;
					if (!v[nx][ny]) {
						perimeter++;
						continue;
					}

					q.push({nx, ny});
					vis[nx][ny] = true;
				}
			}

			if (ans == area && perimeter < ans2) {
				ans2 = perimeter;
			} else if (area > ans) {
				ans = area;
				ans2 = perimeter;
			}
		}
	}

	cout << ans << ' ' << ans2 << '\n';
}
