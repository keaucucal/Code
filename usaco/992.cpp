#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct DSU {
	vector<int> link;

	DSU(int n) : link(n) {
		for (int i = 0; i < n; i++) {
			link[i] = i;
		}
	}

	int find(int x) {
		return link[x] == x ? x : link[x] = find(link[x]);
	}

	bool same(int a, int b) {
		return find(a) == find(b);
	}

	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		link[b] = a;
	}
};

#define width first
#define a second.first
#define b second.second

int main() {
	freopen("wormsort.in", "r", stdin);
	freopen("wormsort.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	vector<int> cows(n); // 0-based
	vector<pair<int, pair<int, int>>> worm(m);
	
	for (auto &c : cows) {
		cin >> c;
		c--;
	}

	for (auto &w : worm) {
		cin >> w.a >> w.b >> w.width;
		w.a--, w.b--;
	}
	sort(worm.begin(), worm.end());

	DSU dsu(n);
	int cur = m; // biggest wormhole
	for (int i = 0; i < n; i++) {
		while (!dsu.same(i, cows[i])) {
			cur--;
			dsu.unite(worm[cur].a, worm[cur].b);
		}
	}

	cout << (cur == m ? -1 : worm[cur].width) << '\n';
}
