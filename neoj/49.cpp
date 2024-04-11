#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int N = 1e5 + 7;

vector<int> cnt(N);
vector<bool> visited(N);
vector<vector<int>> link(N);

void dfs(int x) {
	visited[x] = true;
	for (int nxt : link[x]) {
		if (!visited[nxt]) dfs(nxt);
		cnt[x] += cnt[nxt];
	}
}


void solve() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;
        link[x].push_back(y);
    }

	for (int i = 1; i <= n; i++) {
		if (visited[i]) continue;
		dfs(i);
	}

    int q;
    cin >> q;
	while (q--) {
		int x;
		cin >> x;
		cout << cnt[x] << '\n';
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
		for (int i = 0; i < N; i++) {
			link[i].clear();
			cnt[i] = 1;
			visited[i] = false;
		}
		solve();
    }
}

