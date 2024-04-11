#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <functional>
using namespace std;

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

struct Road {
	// first_row / first_column / second—row / second_column
	int fr, fc, sr, sc;
};

inline bool operator<(const Road &f, const Road &s) {
	return tie(f.fr, f.fc, f.sr, f.sc) < tie(s.fr, s.fc, s.sr, s.sc);
}

int main() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	// 1-based
	int n, k, r;
	cin >> n >> k >> r;
	
	set<Road> roads;
	while (r--) {
		int fr, fc, sr, sc;
		cin >> fr >> fc >> sr >> sc;
		roads.insert({fr, fc, sr, sc});
		roads.insert({sr, sc, fr, fc});
	}

	vector<vector<bool>> cows(n + 1, vector<bool>(n + 1));
	while (k--) {
		int x, y;
		cin >> x >> y;
		cows[x][y] = true;
	}

	vector<vector<bool>> vis(n + 1, vector<bool>(n + 1));
	
	function<int(int, int)> cntcow;
	cntcow = [&](int x, int y) -> int {
		int cnt = cows[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n || vis[nx][ny]) continue;
			if (roads.count({nx, ny, x, y})) continue;
			
			// remember to add this !!!
			vis[nx][ny] = true;
			cnt += cntcow(nx, ny);
		}

		return cnt;
	};

	vector<int> ans;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (vis[i][j]) continue;
			
			vis[i][j] = true;
			int temp = cntcow(i, j);
			if (temp) ans.push_back(temp);
		}
	}

	int dist = 0;
	for (int i = 0; i < ans.size(); i++) {
		for (int j = i + 1; j < ans.size(); j++) {
			dist += ans[i] * ans[j];
		}
	}

	cout << dist << '\n';
}
