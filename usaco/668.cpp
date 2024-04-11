// BFS
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define x first.first
#define y first.second
#define p second

vector<vector<int>> adj;
vector<bool> visited;

int cnt(int c) {
	if (visited[c]) return 0;
	visited[c] = true;
	int ret = 1;
	for (auto i : adj[c]) {
		ret += cnt(i);
	}

	return ret;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	int n;
	cin >> n;
	adj.resize(n);
	vector<pair<pair<int, int>, int>> cows(n);
	for (auto &i : cows) cin >> i.x >> i.y >> i.p;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int dx = cows[i].x - cows[j].x;
			int dy = cows[i].y - cows[j].y;
			if (dx * dx + dy * dy <= cows[i].p * cows[i].p) {
				adj[i].push_back(j);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		visited.assign(n, false);
		ans = max(ans, cnt(i));
	}

	cout << ans << '\n';
}
