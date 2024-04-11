#include <iostream>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

const int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
const int dy[8] = {-1, 1, -1, 0, 1, -1, 0, 1};
// R = 1, Y = 2, B = 4 / O = 3, P = 5, G = 6 / D = 7
map<char, int> m = {{'R', 1}, {'Y', 2}, {'B', 4}, {'O', 3}, {'P', 5}, {'G', 6}, {'D', 7}};

struct node {
	int x, y, level, color;
};

void solve() {
	int n;
	cin >> n;
	int v[n][n];
	memset(v, 0, sizeof(v));

	queue<node> q;
	bool vis[n][n][5];
	memset(vis, 0, sizeof(vis));
	
	for (int i = 0; i < 3; i++) {
		char c;
		int x, y;
		cin >> c >> x >> y;
		q.push({x, y, 0, m[c]});
		vis[x][y][m[c]] = true;
	}

	char c;
	cin >> c;
	if (c == 'D') {
		cout << n * n << '\n';
		return;
	}
	int check = m[c];

	int ans = 0, cnt = 0, cur = 0;
	while (!q.empty()) {
		int x = q.front().x, y = q.front().y, level = q.front().level, color = q.front().color;
		q.pop();
		
		if (level > cur) { // moving onto next level
			// count the answer
			if (cnt < ans) break;
			else ans = cnt;
			cur = level;
		}

		// update the current block color
		if (v[x][y] == check) cnt--;
		v[x][y] += color;
		if (v[x][y] == check) cnt++;

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n || vis[nx][ny][color]) continue;
			
			vis[nx][ny][color] = true;
			q.push({nx, ny, level + 1, color});
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
