#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct PCL {
	int a, b, c, d;
	// {a, b} / {c, d}

	bool inside(PCL other) {
		return (a >= other.a && b >= other.b && c <= other.c && d <= other.d);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);

	int n;
	cin >> n;
	int v[n][n];

	vector<PCL> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c;
			cin >> c;
			v[i][j] = c - 'A';

			for (int k = 0; k <= i; k++) {
				for (int l = 0; l <= j; l++) {

					// Flood fill
					// upper_left = {k, l}, lower_right = {i, j}

					int cnt[26];
					memset(cnt, 0, sizeof(cnt));
					bool vis[n][n];
					memset(vis, false, sizeof(vis));
					for (int a = k; a <= i; a++) {
						for (int b = l; b <= j; b++) {
							if (vis[a][b]) continue;
							cnt[v[a][b]]++;

							queue<pair<int, int>> q;
							q.push({a, b});
							vis[a][b] = true;

							while (!q.empty()) {
								int x = q.front().first, y = q.front().second;
								q.pop();

								for (int t = 0; t < 4; t++) {
									int nx = x + dx[t], ny = y + dy[t];
									if (nx < k || ny < l || nx > i || ny > j || vis[nx][ny]) continue;
									if (v[nx][ny] == v[x][y]) {
										vis[nx][ny] = true;
										q.push({nx, ny});
									}
								}
							}
						}
					}

					
					int kind = 0;
					bool check = false, check2 = false;
					for (const int x : cnt) {
						if (x) kind++;
						if (x == 1) check = true;
						if (x >= 2) check2 = true;
					}

					if (kind == 2 && check && check2) {
						ans.push_back({k, l, i, j});
					}

				}
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < ans.size(); i++) {
		bool flag = true;
		for (int j = 0; j < ans.size(); j++) {
			if (i == j) continue;

			if (ans[i].inside(ans[j])) {
				flag = false;
				break;
			}
		}
		cnt += flag;
	}

	cout << cnt << '\n';
}


